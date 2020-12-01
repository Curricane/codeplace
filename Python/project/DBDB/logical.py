# 值引用
class ValueRef(object):
    def prepare_to_store(self, storage):
        pass

    @staticmethod
    def referent_to_string(referent):
        return referent.encode('utf-8') # string -> bytes

    @staticmethod
    def string_to_referent(string):
        '''
        string: 从文件中宏读取的字节串
        '''
        return string.decode('utf-8') # bytes -> string

    def __init__(self, referent=None, address=0):
        self._referent = referent #引用的值
        self._address = address # 值在文件中的位置

    @property
    def address(self):
        return self._address

    def get(self, storage):
        if self._referent is None and self._address:
            # 将从文件中读取出来的字节串，转换为python中引用的对象
            self._referent = self.string_to_referent(storage.read(self._address))
    
    # 把值存入文件中，并返回在文件中的地址
    def store(self, storage):
        if self._referent is not None and not self._address:
            self.prepare_to_store(storage)
            self._address = storage.write(self.referent_to_string(self._referent))

class LogicalBase(object):
    node_ref_class = None
    value_ref_class = ValueRef

    def __init__(self, storage):
        self._storage = storage
        self._refresh_tree_ref()
    
    def commit(self):
        self._tree_ref.store(self._storage)
        self._storage.commit_root_address(self._tree_ref.address)

    def _refresh_tree_ref(self):
        self._tree_ref = self.node_ref_class(address=self._storage.get_root_address())

    def get(self, key):
        if not self._storage.locked:
            self._refresh_tree_ref()
        # _get方法在子类中实现
        return self._get(self._follow(self._tree_ref), key)
    
    def set(self, key, value):
        if self._storage.lock():
            self._refresh_tree_ref()
        # _insert方法在子类中实现
        self._tree_ref = self._insert( 
            self._follow(self._tree_ref), key, self.value_ref_class(value)
        )

    def pop(self, key):
        if self._storage.lock():
            self._refresh_tree_ref()
        # _delete方法在子类中实现
        self._tree_ref = self._delete(
            self._follow(self._tree_ref), key
        )
    
    def _follow(self, ref):
        return ref.get(self._storage)

    def __len__(self):
        if not self._storage.locked:
            return self._refresh_tree_ref()
        root = self._follow(self._tree_ref)
        if root:
            return root.length
        else:
            return 0