#include<iostream>
using namespace std;

class Node
{
public:
    // 赋值
    int value;
    // 下一个指针
    Node *next;
    // 上一个指针
    Node *previous;

    Node(int value);
    ~Node();

    // 从数组创建双向链表
    static Node *createLinkedList(int arr[], int len);

    // 反转链表
    static Node *reverseLinkedList(Node *root);

    // 合并链表
    static Node *merge(Node *headA, Node *headB);
    static Node *mergeNonRecursion(Node *headA, Node *headB);


    // 打印链表
    Node *debugPrint();
};

Node::Node(int value)
{
    this->value = value;
}

Node::~Node()
{
    next = NULL;
    previous = NULL;
}

// 创建节点
Node* Node::createLinkedList(int arr[], int len) {

    Node *head = nullptr;
    Node *prev = nullptr;
    for (size_t i = 0; i < len; i++)
    {
        Node *node = new Node(arr[i]);
        if (head == nullptr)
        {
            head = node;
        }
        else {
            prev->next = node;
            node->previous = prev;
        }
        prev = node;
    }

    return head;
}

// 反转链表
Node * Node::reverseLinkedList(Node *head){

    Node *cur = head;
    Node *pre = nullptr;

    while (cur != nullptr)
    {
        // 暂存下一个指针
        Node *next = cur->next;

        // 改变当前指针指向
        cur->next = pre;
        // 前一个指针回指
        if (pre != nullptr)
        {
            pre->previous = cur;
        }
        
        // 更新指针
        pre = cur;
        cur = next;
    }

    return pre;
}

// 合并有序链表 (递归方式)
Node * Node::merge(Node *headA, Node *headB) {

    if (headA == nullptr)
    {
        return headB;
    }

    if (headB == nullptr)
    {
        return headA;
    }
    
    Node *newHead;

    if (headA->value > headB->value)
    {
        newHead = headB;
        newHead->next = merge(headA, headB->next);
    }
    else
    {
        newHead = headA;
        newHead->next = merge(headA->next, headB);
    }
    
    return newHead; 
}

// 合并有序链表 (非递归方式)
Node * Node::mergeNonRecursion(Node *headA, Node *headB) {

    if (headA == nullptr)
    {
        return headB;
    }

    if (headB == nullptr)
    {
        return headA;
    }
    
    Node *tempHeadA = headA;
    Node *tempHeadB = headB;
    Node *newHead = new Node(-1);
    Node *tempNewHead = newHead;

    while (tempHeadA != nullptr && tempHeadB != nullptr)
    {
        if (tempHeadA == nullptr)
        {
            tempNewHead->next = tempHeadB;
            tempHeadB = tempHeadB->next;
        }
        else if (tempHeadB == nullptr)
        {
            tempNewHead->next = tempHeadA;
            tempHeadA = tempHeadA->next;
        }
        else if (tempHeadA->value > tempHeadB->value)
        {
            tempNewHead->next = tempHeadB;
            tempHeadA = tempHeadA->next;
        }
        else
        {
            tempNewHead->next = tempHeadA;
            tempHeadB = tempHeadB->next;
        }
    }
    
    return newHead->next;
}

Node * Node::debugPrint() {

    Node *cur = this;
    while (cur != nullptr)
    {
        cout << (cur->value);
        cur = cur->next;

        if (cur != nullptr)
        {
            cout << "->";
        }        
    }
    cout << endl;
}
