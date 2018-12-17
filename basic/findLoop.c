//
// Created by 梁宪松 on 2018-12-17.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "node.c"

/*
 * 判断链表是否有环，使用快慢指针方式
 * */
bool findLoop(NODE *head) {

    NODE *slowP = head; //慢指针, step = 1
    NODE *fastP = head; //快指针, step = 2

    while (fastP != NULL && fastP->next != NULL) {

        slowP = slowP->next;
        fastP = fastP->next->next;

        if (slowP == fastP) {
            break;
        }
    }

    if (fastP == NULL || fastP->next == NULL) {
        // 如果快指针本身 或者 快指针 下个节点 为空，则没有环
        return false;
    }else {
        return true;
    }
}

/*
 * 计算环的长度
 *                       b    P
 *       a           ---------*---
 * ----------------*|             |  c
 *                   -------------
 *  慢指针： a + b
 *  快指针： a + b + b + c
 *  可得： a == c
 *
 *  所以环的长度  L = a + b + c = 2a + b
 *  只需要找到P点， 然后同速率的两个指针，一个放置于P点，一个放置于head，
 *  再次相遇的地方长度 就可求出环长度
 *  要求环的入口也是类似的操作
 * */
int loopLen(NODE *head) {

    if (findLoop(head) == false) return 0;

    int len = 0;
    NODE *slowP = head; //慢指针, step = 1
    NODE *fastP = head; //快指针, step = 2

    // 第一次相遇
    while (fastP != NULL && fastP->next != NULL) {

        slowP = slowP->next;
        fastP = fastP->next->next;

        if (slowP == fastP) {
            break;
        }else {
            // 长度自增
            len ++;
        }
    }

    // 第二次相遇
    slowP = head;
    while (fastP != NULL) {

        // 步长都为1
        slowP = slowP->next;
        fastP = fastP->next;

        if (slowP == fastP) {
            break;
        }else {
            // 长度自增
            len ++;
        }
    }

    return  len;
}
