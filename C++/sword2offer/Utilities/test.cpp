#include "BinaryTree.h"

// test create and print a bitree which has only one node
void test1()
{
    int array[] = {1};
    std::vector<int> a(array, array+1);
    BinaryTreeNode* pRoot = CreateBinaryTreeByArray(a);
    std::cout << "[1] create a BTree: " << std::endl;
    PrintBinaryTree(pRoot);
}

// test create and print a normal bitree 
void test2()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> a(array, array + 10);
    BinaryTreeNode* pRoot = CreateBinaryTreeByArray(a);
    std::cout << "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] create a BTree: " << std::endl;
    PrintBinaryTree(pRoot);
}

// test create and print a null bitree
void test3()
{
    std::vector<int> a;
    BinaryTreeNode* pRoot = CreateBinaryTreeByArray(a);
    std::cout << "[] create a BTree: " << std::endl;
    PrintBinaryTree(pRoot);
}

// test create and print a single line bitree
void test4()
{
    int array[] = {1, 2, -1, 3, -1, -1, -1, 4};
    std::vector<int> a(array, array + 8);
    BinaryTreeNode* pRoot = CreateBinaryTreeByArray(a);
    std::cout << "[1, 2, -1, 3, -1, -1, -1, 4] create a BTree: " << std::endl;
    PrintBinaryTree(pRoot);
}


int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}