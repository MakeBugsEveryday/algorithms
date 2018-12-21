//
// Created by 梁宪松 on 2018-12-20.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 链表定义
#include "node.c"

// 根节点
NODE *_root = NULL;

/*
 * 递归获取元素
 * */
int get_recur(NODE *root, int key) {

    if (root == NULL) { return -1;}
    if (root->key == key) {
        return root->val;
    } else if (key < root->key) {
        return get_recur(root->left, key);
    } else {
        return get_recur(root->right, key);
    }
}

/*
 * 递归插入元素
 *
 * 意味着重置每个父节点指向子节点的链接
 * */
NODE* put_recur(NODE *root, int key, int val) {

    if (root == NULL) {
        NODE *node = createNode(key, val);
        printf("create node: key: %d, val: %d\n", key, val);
        return node;
    }

    if (root->key == key) {
        root->val = val;
    }else if (key < root->key) {
        root->left = put_recur(root->left, key, val);
    } else {
        root->right = put_recur(root->right, key, val);
    }

    return root;
}


/*
 * 删除最小节点
 * */
NODE* deleteMinNode(NODE *root) {

    if (root->left == NULL) {
        // 左子节点为空的话，返回右子节点
        return root->right;
    }

    // 删除子节点
    root->left = deleteMinNode(root->left);

    // 返回当前节点，最终会返回根节点
    return root;
}

/*
 * 获取最小节点
 * */
NODE* getMin(NODE *root) {
    if (root->left == NULL) {
        return root;
    }

    return getMin(root->left);
}

/*
 * 删除节点，这是最难的
 *
 * 方法：删除节点 x 之后用它的后继节点填补他的位置
 * */
NODE *deleteNode(NODE *root, int key) {

    if (root == NULL) {
        return NULL;
    }

    // 查找节点
    if (root->key > key) {
        // 查找左子树
        return deleteNode(root->left, key);
    } else if (root->key < key) {
        // 查找右子树
        return deleteNode(root->right, key);
    } else {
        // 找到了节点，删除
        if (root->right == NULL) {
            // 右子树为空
            return root->left;
        }
        if (root->left == NULL) {
            // 左子树为空
            return root->right;
        }

        NODE *temp = _root;
        // 获取右子树最小节点，作为后继节点
        root = getMin(temp->right);
        // 然后删除该节点
        root->right = deleteMinNode(temp->right);
        // 更新节点
        root->left = temp->left;
    }

    // 返回被删除节点
    return root;
}


/*
 * 范围查找
 * */
void getKeys() {

}

/*
 * 前序遍历
 * */
void preOrderTranverse(NODE *root) {

    if (root == NULL) { return;}
    printf("preOrderTranverse key: %d, val: %d\n", root->key, root->val);
    preOrderTranverse(root->left);
    preOrderTranverse(root->right);
}

/*
 * 中序遍历
 * */
void midOrderTranverse(NODE *root) {

    if (root == NULL) { return;}
    midOrderTranverse(root->left);
    printf("midOrderTranverse key: %d, val: %d\n", root->key, root->val);
    midOrderTranverse(root->right);
}

/*
 * 后序遍历
 * */
void suffOrderTranverse(NODE *root) {

    if (root == NULL) { return;}
    suffOrderTranverse(root->left);
    suffOrderTranverse(root->right);
    printf("suffOrderTranverse key: %d, val: %d\n", root->key, root->val);
}

/*
 * bst 插入难度和查找难度差不多
 * */
void demo() {

    for(int i = 1; i< 8; i++) {
        _root = put_recur(_root, i, i);
    }

    printf("root node: key: %d, val: %d\n", _root->key, _root->val);

    NODE *temp = getMin(_root);
    printf("root node: %d\n", temp->key);
    NODE *deleted = deleteNode(_root, 5);
    preOrderTranverse(_root);
}
