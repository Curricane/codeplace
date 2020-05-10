#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode():m_nValue(0), 
                     m_pLeft(nullptr), 
                     m_pRight(nullptr){};
    BinaryTreeNode(int value):m_nValue(value), 
                              m_pLeft(nullptr), 
                              m_pRight(nullptr){};
};

void ConnectTreeNodes(BinaryTreeNode *pParent, 
                      BinaryTreeNode* pLeft=nullptr, 
                      BinaryTreeNode* pRight=nullptr);
int GetHeight(BinaryTreeNode *pRoot);
void PrintBinaryTree(BinaryTreeNode *pRoot);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);

BinaryTreeNode* CreateBinaryTreeByArray(std::vector<int> a);