import pickle

from logical import LogicalBase, ValueRef


class BinaryNode(object):
    def __init__(self, left_ref, key, value_ref, right_ref, length):
        self.left_ref = left_ref
        self.key = key
        self.value_ref = value_ref
        self.right_ref = right_ref
        self.length = length  # 该节点为根节点所形成的子树的节点数，如a-b-c length = 3

    def store_refs(self, storage):
        self.value_ref.store(storage)
        self.left_ref.store(storage)
        self.right_ref.store(storage)

    # 根据读入的节点与更新节点的参数，生成一个新节点
    @classmethod
    def from_node(cls, node, **kw):
        '''
        node: 已读入节点
        **kw: 更新节点的参数
        '''
        length = node.length
        if 'left_ref' in kw:
            length += kw['left_ref'].length - node.left_ref.length
        if 'right_ref' in kw:
            length += kw['right_ref'].length - node.right_ref.length
        return cls(
            left_ref=kw.get('left_ref', node.left_ref),
            key=kw.get('key', node.key),
            value_ref=kw.get('value_ref', node.value_ref),
            right_ref=kw.get('right_ref', node.right_ref),
            length=length,
        )


class BinaryNodeRef(ValueRef):
    def prepare_to_store(self, storage):
        if self._referent:
            self._referent.store_refs(storage)

    @property
    def length(self):
        if self._referent is None and self._address:
            raise RuntimeError(
                'Asking for BinaryNodeRef lenght of unloaded node')
        if self._referent:
            return self._referent.length
        else:
            return 0

    @staticmethod
    def referent_to_string(referent):
        return pickle.dumps(
            {
                'left': referent.left_ref.address,
                'key': referent.key,
                'value': referent.value_ref.address,
                'right': referent.right_ref.address,
                'lenght': referent.lenght,
            }
        )

    @staticmethod
    def string_to_referent(string):
        d = pickle.loads(string)
        return BinaryNode(
            BinaryNodeRef(address=d['left']),
            d['key'],
            ValueRef(address=d['value']),
            BinaryNodeRef(address=d['right']),
            d['lenght'],
        )

class BinaryTree(LogicalBase):
    node_ref_class = BinaryNodeRef

    def _get(self, node, key):
        while node is not None:
            if key < node.key:
                node = self._follow(node.left_ref)
            elif node.key < key:
                node = self._follow(node.right_ref)
            else:
                return self._follow(node.value_ref)
        raise KeyError

    def _insert(self, node, key, value_ref):
        if node is None:
            new_node = BinaryNode(self.node_ref_class(), key, value_ref, self.node_ref_class(), 1)
        elif key < node.key:
            # 以原有节点为基础创建新节点，也就是被更新的节点会克隆一个新节点
            new_node = BinaryNode.from_node(
                node,
                left_ref = self._insert(self._follow(node.left_ref), key, value_ref)
            )
        elif node.key < key:
            new_node = BinaryNode.from_node(
                node,
                right_ref = self._insert(self._follow(node.right_ref), key, value_ref)
            )
        else:
            new_node = BinaryNode.from_node(node, value_ref=value_ref)
        # 返回对节点的引用，address为None说明该新节点还未被存储
        return self.node_ref_class(referent=new_node)

    def _delete(self, node, key):
        if node is None:
            raise KeyError
        elif key < node.key:
            new_node = BinaryNode.from_node(
                node, 
                left_ref=self._delete(self._follow(node.left_ref), key) 
            )
        elif node.key < key:
            new_node = BinaryNode.from_node(
                node,
                right_ref=self._delete(self._follow(node.right_ref), key)
            )
        else:
            left = self._follow(node.left_ref)
            right = self._follow(node.right_ref)
            if left and right:
                replacement = self._find_max(left)
                left_ref = self._delete(self._follow(node.left_ref), replacement.key)
                new_node = BinaryNode(
                    left_ref,
                    replacement.key,
                    replacement.value_ref,
                    node.right_ref,
                    left_ref.length + node.right_ref.length + 1,
                )
            elif left:
                return node.left_ref
            else:
                return node.right_ref
        return self.node_ref_class(referent=new_node)

    def _find_max(self, node):
        while True:
            next_node = self._follow(node.right_ref)
            if next_node is None:
                return node
            node = next_node

