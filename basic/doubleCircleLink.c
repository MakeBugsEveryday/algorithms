//
// Created by 梁宪松 on 2018-12-17.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 链表定义
typedef struct Node{

    struct Node *next;
    struct Node *prev;
    int val;
} NODE;

// 链表头节点
NODE* _head = NULL;
NODE* _tail = NULL;

// 创建节点
NODE* defaultNode(int val) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return  node;
}

// 创建链表, 返回头结点
NODE* creatNodes(int nums) {

    // 头节点
    _head = defaultNode(-1);
    _tail = _head;
    NODE *cur = _head;

    for (int i = 0; i < nums; i++) {
        NODE *node = defaultNode(i);
        cur->next = node;
        node->prev = cur;
        cur = node;

        // 记录尾节点
        _tail = cur;
    }
    // head 和 tail 的指向
    _tail->next = _head;
    _head->prev = _tail;
    return _head;
}


// 插入节点
void insertNode(int val){

    NODE *node = defaultNode(val);
    // 寻找合适位置插入

    node->next = _head->next;
    node->prev = _head;

    _head->next->prev = node;
    _head->next = node;
}

// 查找节点
NODE * searchNode(int val) {

    NODE *cur = _head;
    while (cur != NULL) {

        if (cur->val == val) {
            return cur;
        }
        cur = cur->next;

        if (cur == _head) { break;}
    }
    return  NULL;
}

void deleteNode(int val) {
    NODE *toDelItem = searchNode(val);
    if (toDelItem == NULL){ return;}

    toDelItem->next->prev = toDelItem->prev;
    toDelItem->prev->next = toDelItem->next;

    toDelItem->next = NULL;
    toDelItem->prev = NULL;
}

// 遍历各个节点
void tranverse() {

    NODE *_temp = _head;
    int tag = 0;
    while (_temp != NULL) {
        if (tag == 0) {
            printf("double circle linked map: %d", _temp->val);
        } else {
            printf(" -> %d", _temp->val);
        }
        if (_temp->next != NULL && (tag == 0 || _temp != _head)) {
            _temp = _temp->next;
        }else {
            printf("\n");
            break;
        }
        tag ++;
    }
}


// 演示
void demo() {

    _head = defaultNode(-1);
    _tail = _head;
    _head->prev = _tail;
    _tail->next = _head;
//    creatNodes(5);
    insertNode(0);
    insertNode(1);
    insertNode(2);
    insertNode(3);
    tranverse();

    deleteNode(1);
    tranverse();
}