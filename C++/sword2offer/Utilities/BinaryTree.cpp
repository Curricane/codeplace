#include <cstdio>
#include <cmath>
#include "BinaryTree.h"

void PrintWithSpaces(int num);

void ConnectTreeNodes(BinaryTreeNode *pParent, 
                      BinaryTreeNode* pLeft, 
                      BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

int GetHeight(BinaryTreeNode *pRoot)
{
    if (nullptr == pRoot)
    {
        return 0;
    }
    int lh = GetHeight(pRoot->m_pLeft);
    int rh = GetHeight(pRoot->m_pRight);
    return lh > rh ? lh + 1 : rh + 1;
}


void PrintBinaryTree(BinaryTreeNode *pRoot)
{
    // used for level traverse
    std::queue<BinaryTreeNode*> q;
    int level = GetHeight(pRoot);

    //get nums of nodes in this tree
    int size = pow(2, level) - 1;

    // used to count how many nodes has used
    int count = 0;
    int nowlevel = 1;
    int nowheight = level;
    q.push(pRoot);
    while (count <= size)
    {   
        // nums of nodes in this level
        int numsnodes = pow(2, nowlevel - 1);

        //the half nums child nodes of the node in this level, 
        // used to count the spaces before and after the node
        int halfchildnums = pow(2, nowheight-1) - 1;

        //traverse this level nodes
        for (int i = 0; i < numsnodes; ++i)
        {
            BinaryTreeNode* node = q.front();
            q.pop();

            // this node has used
            ++count;
            PrintWithSpaces(halfchildnums);
            if ( nullptr == node)
            {
                std::cout << "  ";
                PrintWithSpaces(halfchildnums);
                std::cout << "  "; // this is a filler for its patent node
                q.push(nullptr); // be careful you should avoid nullptr->member
                q.push(nullptr);
            }    
            else
            {
                printf("%2d", node->m_nValue);
                PrintWithSpaces(halfchildnums);
                std::cout << "  "; // this is a filler for its patent node
                q.push(node->m_pLeft);
                q.push(node->m_pRight);
            } 

        }
        ++nowlevel;
        --nowheight;
        std::cout << std::endl;
    }

}



void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if (pNode != nullptr)
    {   
        std::cout << "[";
        if (pNode->m_pLeft != nullptr)
            std::cout << "(" << pNode->m_pLeft->m_nValue << ")";
        else 
            std::cout << "(null)";

        std::cout << "-(" << pNode->m_nValue << ")+";

        if (pNode->m_pRight != nullptr)
            std::cout << "(" << pNode->m_pRight->m_nValue << ")";
        else 
            std::cout << "(null)";
        std::cout << "]" << std::endl;
    }
    else 
    {
        std::cout << "[null]" << std::endl;
    }
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);
    if (pRoot != nullptr)
    {   
        if (pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);
        if (pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}
void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        DestroyTree(pRoot->m_pLeft);
        DestroyTree(pRoot->m_pRight);

        delete pRoot;
        pRoot = nullptr;
    }
}

BinaryTreeNode* CreateBinaryTreeByArray(std::vector<int> a)
{
    int length = a.size();
    if (length <= 0)
        return nullptr;
    std::queue<BinaryTreeNode*> q;
    BinaryTreeNode* pRoot = new BinaryTreeNode(a[0]);
    int pos = -1;
    q.push(pRoot);
    while (!q.empty() && pos < length / 2)
    {
        BinaryTreeNode* node = q.front();
        q.pop();
        ++pos;
        if (nullptr == node)
        {
            q.push(nullptr);
            q.push(nullptr);
            continue;
        }
        int leftnum = pos * 2 + 1;
        int rightnum = pos * 2 + 2;
        if(leftnum >= length || a[leftnum] == -1)
        {
            node->m_pLeft = nullptr;
        }
        else
        {
            node->m_pLeft = new BinaryTreeNode(a[leftnum]);
        }
        q.push(node->m_pLeft);

        if(rightnum >= length || a[rightnum] == -1)
        {
            node->m_pRight = nullptr;
        }
        else
        {
            node->m_pRight = new BinaryTreeNode(a[rightnum]);
        }
        q.push(node->m_pRight);
  
    }
    std::cout << "over";
    return pRoot;
}

void PrintWithSpaces(int num)
{
    for(int i = 0; i< num; ++i)
        std::cout << "  ";
}

bool isEqual(BinaryTreeNode *A, BinaryTreeNode *B)
{
    if(nullptr == B && nullptr == A)
        return true;
    if(nullptr == A && B != nullptr)
        return false;
    if(nullptr != A && nullptr == B)
        return false;
    return A->m_nValue == B->m_nValue && isEqual(A->m_pLeft, B->m_pLeft) && isEqual(A->m_pRight, B->m_pRight);
};