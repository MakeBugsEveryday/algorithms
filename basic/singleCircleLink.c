//
// Created by 梁宪松 on 2018-12-17.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 链表定义
typedef struct Node{

    struct Node *next;
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
    return  node;
}

// 创建链表, 返回头结点
NODE* creatSortedLink(int nums) {

    NODE *cur = NULL;
    for (int i = 0; i < nums; i ++) {

        NODE *node = defaultNode(i);
        _tail = node;

        if (i == 0) {

            _head = node;
            // 指针回指向head
            _head->next = _head;

            // 暂存当前指针
            cur = _head;
        }else {
            cur->next = node;
            node->next = _head;

            // 暂存当前指针
            cur = node;
        }
    }

    return _head;
}

// 插入节点
void insertNode(int val) {

    // 创建节点
    NODE *node = defaultNode(val);

    NODE *cur = _head;
    while (cur != NULL) {

        // 遍历节点, 寻找合适的位置插入
        if (node->val >= cur->val) {
            // 插入节点
            node->next = cur->next;
            cur->next = node;
            // 跳出循环
            break;
        }
        // 跳入下一个节点
        cur = cur->next;

        // 跳出循环
        if (cur == _head) { break;}
    }
}

// 删除节点
void deleteNode(int val) {

    NODE *cur = _head;
    if (cur->val == val) {
        // 删除节点
        _tail->next = cur->next;
        _head = cur->next;
        cur->next = NULL;
        return;
    }

    while (cur->next != NULL) {


        if (cur->next->val == val) {
            // 删除节点
            cur->next = cur->next->next;
        }
        // 跳入下一个节点
        cur = cur->next;

        // 跳出循环
        if (cur == _head) { break;}
    }
}

// 遍历各个节点
void tranverse() {

    NODE *_temp = _head;
    int tag = 0;
    while (_temp != NULL) {
        if (tag == 0) {
            printf("circle linked map: %d", _temp->val);
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

    creatSortedLink(5);
    insertNode(8);
    insertNode(11);
//    deleteNode(4);
    tranverse();
}