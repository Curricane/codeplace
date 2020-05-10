#include <exception>
#include "../Utilities/BinaryTree.h"

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

int find(int* start, int len, int target);
 

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (length <= 0)
        return nullptr;
    BinaryTreeNode* pRoot = new BinaryTreeNode(preorder[0]);

    int idx = find(inorder, length, preorder[0]); 
    if (-1 ==  idx)
    {
        std::cout << "error: unmatched inorder" << std::endl;
        //throw std::exception("Invalid input.");
        return pRoot;
    }

    int llen = idx;

    // length is the nums of num start from 1, however idx from 0, 
    // so we should minus 1 more
    int rlen = length - idx -1; 

    //left
    pRoot->m_pLeft = Construct(preorder + 1, inorder, llen);

    //right
    pRoot->m_pRight = Construct(preorder + llen + 1, inorder + idx + 1, rlen);
    return pRoot;
}

//find idx of target from 0
int find(int* start, int len, int target)
{
    int i = 0;
    for (; i < len; ++i)
    {
        if (target == *(start + i))
            return i;
    }
    std::cout << "cannt find target in the array" << std::endl;
    return -1;
}


// test a nomal bitree
void test1()
{
    std::cout << "test a nomal bitree" << std::endl;
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode* pRoot = Construct(preorder, inorder, 8);
    PrintBinaryTree(pRoot);
    //PrintTree(pRoot);
}

// test one node bitree
void test2()
{
    std::cout << "test one node bitree" << std::endl;
    int preorder[] = {1};
    int inorder[] = {1};
    BinaryTreeNode* pRoot = Construct(preorder, inorder, 1);
    PrintBinaryTree(pRoot);
    //PrintTree(pRoot);
}

// test a single childrens bitree
void test3()
{
    std::cout << "test a single childrens bitree" << std::endl;
    int preorder[] = {1, 2, 3, 4, 5, 6};
    int inorder[] = {6, 5, 4, 3, 2, 1};
    BinaryTreeNode* pRoot = Construct(preorder, inorder, 6);
    PrintBinaryTree(pRoot);
    //PrintTree(pRoot);
}


int main()
{
    test1();
    test2();
    test3();

}