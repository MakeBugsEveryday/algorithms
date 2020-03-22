//
// Created by 梁宪松 on 2018-12-20.
//

// 链表定义
typedef struct Node{

    struct Node *left;
    struct Node *right;
    int val;
    int key;
} NODE;


// 创建节点
NODE* createNode(int key, int val) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->val = val;
    return  node;
}
