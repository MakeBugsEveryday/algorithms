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

// 链表头
NODE *_head = NULL;
// 链表尾
NODE *_tail = NULL;

// 首部插入
void insertNodeAtHead(NODE *node) {

    // head 和 要插入的相等
    if (_head == node) {return;}

    node->prev = NULL;
    // 头节点不为空
    if (_head != NULL) {

        node->next = _head;
        _head->prev = node;
        _head = node;
    } else {

        _head = _tail = node;
    }
}

// 节点提升至首部
void bringNodeToHead(NODE *node) {

    if (_head == node) {return;}

    // 从链表中断开
    if (_tail == node) {

        _tail = _tail->prev;
        _tail->next = NULL;
    } else {

        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // 连接链表
    _head->prev = node;
    node->next = _head;
    _head = node;
    node->prev = NULL;
}

// 移除尾节点
void removeTailNode() {
    // 判断头尾节点是否一致
    if (_head == _tail) {
        _head = _tail = NULL;
    }else {
        // 重置 tail 节点
        _tail = _tail->prev;
        _tail->next = NULL;
    }
}

// 删除节点
void removeNode(NODE *node) {

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (_head == node) {
        _head = node->next;
    }
    if (_tail == node) {
        _tail = node->prev;
    }
}

// 移除所有节点
void removeAll() {

    while (_head != NULL) {
        NODE *temp = _head;
        _head=_head->next;
        temp->next = temp->prev = NULL;
    }
    _head = _tail = NULL;
}

NODE* defaultNode(int val) {
    NODE *node1 = (NODE *)malloc(sizeof(NODE));
    node1->val = val;
    node1->next = NULL;
    node1->prev = NULL;
    return  node1;
}

void reverse() {

    NODE *_temp = _head;
    int tag = 0;
    while (_temp != NULL) {
        if (tag == 0) {
            printf("linked map: %d", _temp->val);
        } else {
            printf(" -> %d", _temp->val);
        }
        tag ++;
        if (_temp->next != NULL) {
            _temp = _temp->next;
        }else {
            printf("\n");
            break;
        }
    }
}

void demo() {


    insertNodeAtHead(defaultNode(1));
    insertNodeAtHead(defaultNode(2));
    insertNodeAtHead(defaultNode(3));
    insertNodeAtHead(defaultNode(4));
    reverse();

    removeTailNode();
    reverse();
    removeTailNode();
    reverse();
}
