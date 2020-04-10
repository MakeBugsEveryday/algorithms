#include<iostream>
#include"../node/node.hpp"
 

int main(int argc, char const *argv[])
{
    int arr[] = {0, 0, 1, 2, 6, 2, 3, 4, 5};
    // 创建链表
    Node *head = Node::createLinkedList(arr, sizeof(arr) / sizeof(arr[0]));
    head->debugPrint();
    // head->debugPrintReversingly();

    // 删除重复节点
    // Node::removeDuplicate1(head);
    // head->debugPrint();

    // 删除重复节点2
    // Node *newHead = Node::removeDuplicate2(head);
    // newHead->debugPrint();

    // 删除所有节点
    // Node *deleteHead = Node::removeAllValuesInElement(head, 2);
    // deleteHead->debugPrint();

    // 反转链表
    head = Node::reverseLinkedList(head);
    head->debugPrint();

    head = Node::reverseLinkedListRecursion(head);
    head->debugPrint();
    
    // 创建链表
    // int arr2[] = {2, 4, 6, 8, 10, 12};
    // Node *head2 = Node::createLinkedList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    // head2->debugPrint();

    // // 递归合并
    // Node *mergedHead = Node::merge(head, head2);
    // mergedHead->debugPrint();

    // // 非递归合并
    // Node *mergedNonRecursiveHead = Node::mergeNonRecursion(head, head2);
    // mergedNonRecursiveHead->debugPrint();

    // 将小于和大于给定值的节点划分到链表两侧
    // head = Node::partitionLinkedList(head, 5);
    // head->debugPrint();

    // // 将奇偶数节点划分到链表两侧
    // head = Node::oddEvenLinkedList(head);
    // head->debugPrint();
    
    return 0;
}
