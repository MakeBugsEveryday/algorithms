//
// Created by 梁宪松 on 2018-12-16.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 链表定义
typedef struct Node{

    int val;
    struct Node *next;
} NODE;


// 栈顶
NODE *_top;
int size = 0;

// 判断是否为空
bool isEmpty() {

    return _top->val == 0;
}

// push
void push(int val) {
    // 创建节点
    NODE *temp = NULL;
    temp = malloc(sizeof(temp));
    temp->val = val;

    // 栈顶添加元素
    temp->next = _top;

    // 替换top
    _top = temp;

    printf("push: %d\n", _top->val);
}

// pop
int pop() {

    if (isEmpty()) {return -1;}
    int value = _top->val;

    _top = _top->next;
    printf("pop: %d\n", value);
    return value;
}

// 遍历
void reverse() {

    NODE *_temp = _top;

    printf("value: %d\n", _temp->val);
    printf("value: %d\n", _temp->next->val);


//    while (_temp.val != 0) {
//        printf("value: %d\n", _temp.val);
//        if (_temp.next != NULL) {
//            _temp = *_temp.next;
//        }else {
//            break;
//        }
//    }
}

void demo() {

    // 用例
//    _top.val = 1;
    push(1);
    push(2);
    reverse();

//    pop();
//    pop();
//    printf("value: %d\n", _top.val);
}