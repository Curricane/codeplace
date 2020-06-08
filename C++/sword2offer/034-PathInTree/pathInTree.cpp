// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

/**
 * 测试用例：
 * 1，空
 * 2. 只有根节点 有路径 无路径
 * 3. 正常的二叉树 有路径 无路径 无路径但子树有路径
 * 4. 单边二叉树 有路径 无路径 无路径但子树有路径
*/

/**
 * 思路：
 * 记录路径：
 *  栈/队列 用于记录树的路径
 *  栈/队里 用于记录数值
 * 遍历方式：
 *  前序遍历
*/

#include "BinaryTree.h"

#include <iostream>
#include <vector>

using std::vector;

bool FindPath(BinaryTreeNode *pRoot, vector<BinaryTreeNode*> &nodePath, vector<int> &numPath, int target)
{
    //终止条件
    if (nullptr == pRoot)
        return false;
    
    // 计算当前的和，并入值路径
    int sum = numPath.back() + pRoot->m_nValue;
    numPath.push_back(sum);
    nodePath.push_back(pRoot);
    if (nullptr == pRoot->m_pLeft && nullptr == pRoot->m_pRight && sum == target)
        return true;

    
    // 在左子树中寻找
    if(pRoot->m_pLeft != nullptr)
    {
        bool ret = FindPath(pRoot->m_pLeft, nodePath, numPath, target);
        if (ret)
            return true;
    }

    // 在右子树中寻找
    if(pRoot->m_pRight != nullptr)
    {
        bool ret = FindPath(pRoot->m_pRight, nodePath, numPath, target);
        if (ret)
            return true;
    }


    // 这个节点没找到，退出，清除值路径记录
    numPath.pop_back();
    nodePath.pop_back();
    return false;
}

void Test(const char *name, BinaryTreeNode *pRoot, int target,  bool expect)
{
    printf("***********%s, target is %d  : ", name, target);
    
    bool ret;
    vector<BinaryTreeNode*> nodePath;
    vector<int> numPath;
    numPath.push_back(0);
    ret = FindPath(pRoot, nodePath, numPath, target);
    if (ret == expect)
        std::cout << "passed" << std::endl;
    else
    {
        std::cout << "failed" << std::endl;
    }
    std::cout << "the tree is: " << std::endl;
    PrintBinaryTree(pRoot);
    std::cout << "the nodePath is: " << std::endl;
    for (int i = 0; i < nodePath.size(); ++i)
    {
        std::cout << nodePath[i]->m_nValue << "-->";
    }
    std::cout << std::endl;

}

//            10
//         /      \
//        5        12
//       / \        
//      4  7     
// 有两条路径上的结点和为22
void Test1()
{
    BinaryTreeNode* pNode10 = new BinaryTreeNode(10);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode12 = new BinaryTreeNode(12);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode7 = new BinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22, true);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       / \        
//      4  7     
// 没有路径上的结点和为15
void Test2()
{
    BinaryTreeNode* pNode10 = new BinaryTreeNode(10);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode12 = new BinaryTreeNode(12);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode7 = new BinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15, false);

    DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
// 有一条路径上面的结点和为15
void Test3()
{
    BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(3);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(2);
    BinaryTreeNode* pNode1 = new BinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15, true);

    DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// 没有路径上面的结点和为16
void Test4()
{
    BinaryTreeNode* pNode1 = new BinaryTreeNode(1);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(2);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(3);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16, false);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test5()
{
    BinaryTreeNode* pNode1 = new BinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1, true);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", nullptr, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
