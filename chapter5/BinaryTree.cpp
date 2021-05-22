/*
************************************************
***Author: SheepTAO
***File description: 二叉树的基本操作
************************************************
*/

#include <iostream>

using std::cout;
using std::endl;
using ElemType = int;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChild, *rChild;
}BiTNode;

void InsertNode(BiTNode*&, ElemType);                                   // 插入节点
void PreOrder(const BiTNode*);                                          // 先序遍历
void InOrder(const BiTNode*);                                           // 中序遍历
void PostOrder(const BiTNode*);                                         // 后序遍历

int main()
{
    BiTNode* tree = nullptr;
    int dataArr[] = {42, 63, 15, 78, 23, 99, 65, 30, 73, 88, 12};
    size_t size = sizeof(dataArr)/sizeof(dataArr[0]);

    for (size_t i = 0; i < size; ++i) {
        InsertNode(tree, dataArr[i]);
    }
    InOrder(tree);  cout << endl;
    PostOrder(tree);    cout << endl;

    return 0;
}

void InsertNode(BiTNode*& node, ElemType data) {
    if (!node) {
        node = new BiTNode;
        node->data = data;
        node->lChild = nullptr;
        node->rChild = nullptr;
    } else {
        if (data < node->data)
            InsertNode(node->lChild, data);
        else 
            InsertNode(node->rChild, data);
    }
}

void PreOrder(const BiTNode *node) {
    if (node) {
        cout << node->data << '\t';
        PreOrder(node->lChild);
        PreOrder(node->rChild);
    }
}

void InOrder(const BiTNode *node) {
    if (node) {
        InOrder(node->lChild);
        cout << node->data << '\t';
        InOrder(node->rChild);
    }
}

void PostOrder(const BiTNode *node) {
    if (node) {
        PostOrder(node->lChild);
        PostOrder(node->rChild);
        cout << node->data << '\t';
    }
}