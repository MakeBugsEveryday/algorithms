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
    // 翻转链表（递归）
    static Node *reverseLinkedListRecursion(Node *root);

    // 合并链表
    static Node *merge(Node *headA, Node *headB);
    static Node *mergeNonRecursion(Node *headA, Node *headB);

    // 查找链表的交点
    static Node *findIntersectionNode(Node *headA, Node *headB);

    // 查找链表是否有环
    // 延伸：求环的长度
    // 延伸：求环入口节点
    // 延伸：求链表长度
    static bool findCircle(Node *headA);

    // 查找链表倒数第n个节点
    static Node *findKthToTail(Node *head, int k);

    // 删除重复节点，只保留一个
    static Node *removeDuplicate1(Node *head);
    // 删除重复节点，重复的不保留
    static Node *removeDuplicate2(Node *head);

    // 删除链表所有所有 k 值
    static Node *removeAllValuesInElement(Node *head, int k);

    // 将小于和大于给定值的节点划分到链表两侧
    static Node *partitionLinkedList(Node *head, int k);

    // 将奇数和偶数的节点分在链表两侧
    static Node *oddEvenLinkedList(Node *head);

    // 打印链表
    Node *debugPrint();
    // 反向打印
    Node *debugPrintReversingly();
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

// 递归翻转链表
Node *Node::reverseLinkedListRecursion(Node *root) {

    if (root->next == NULL) {
        return root;
    }

    // 获取到新的头节点
    Node *newRoot = reverseLinkedListRecursion(root->next);

    // 1->2->3->4    
    // 改变指针指向： 1->2->3<-4， 
    // 依次递归      1->2<-3<-4
    // 依次递归      1<-2<-3<-4
    // 返回root     4
    root->next->next = root;
    // 清空 next 指针
    root->next = NULL;

    return newRoot;
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

// 查找链表交点
Node * Node::findIntersectionNode(Node *headA, Node *headB) {

    // 首尾相连，判断是否有环即可
}

// 查找是否有环
bool Node::findCircle(Node *head) {

    // 快慢指针
    Node *slowPointer = head;
    Node *fastPointer = head;

    while (fastPointer->next != nullptr && fastPointer->next->next != nullptr &&
            slowPointer->next != nullptr)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if (slowPointer == fastPointer)
        {
            return true;
        }
    }
    
    return false;
}

// 查找倒数第n个节点
static Node *findKthToTail(Node *head, int k) {
    
    Node *tailNode = head;
    // 跳到第 k 个节点
    for (size_t i = 0; i < k++; i++)
    {
        if (tailNode == nullptr)
        {
            return nullptr;
        }
        
        tailNode = tailNode->next;
    }
    
    Node *behindNode = head;

    // tailNode 和 behindNode 等距离，直到 tailNode-> next 到了末尾
    while (tailNode->next != nullptr)
    {
        behindNode = behindNode->next;
        tailNode = behindNode->next;
    }
    
    return behindNode;
}

// 删除重复节点
Node * Node::removeDuplicate1(Node *head) {

    Node *cur = head;

    while (cur != nullptr && cur->next != nullptr)
    {
        if (cur->value == cur->next->value)
        {
            Node *node2Delete = cur->next;

            // 短开 cur->next 连接
            cur->next = cur->next->next;
            // 回指
            cur->next->next->previous = cur;

            // 删除 cur->next 节点
            node2Delete->next = nullptr;
            node2Delete->previous = nullptr;
            delete node2Delete;
        }
        else {
            cur = cur->next;
        }
    }
}

// 删除重复节点，不保留节点
Node * Node::removeDuplicate2(Node *head) {

    // 当前节点
    Node *cur = head;
    // 前一个节点
    Node *previous = nullptr;

    while (cur != nullptr && cur->next != nullptr)
    {
        
        if (cur->value == cur->next->value)
        {
            // 要删除的节点
            Node *node2DeleteTail = cur;
            // 继续向下查找要删除的指针
            while (node2DeleteTail->next != nullptr && node2DeleteTail->value == node2DeleteTail->next->value)
            {
                node2DeleteTail = node2DeleteTail->next;
            }
            
            // 如果当前是第一个节点
            if (cur == head)
            {
                // 直接指向要删除节点的下一个节点
                head = node2DeleteTail->next;
                // 更新指针
                cur = head;
                previous = nullptr;
            }
            else
            {
                // 断开 previous 和 node2DeleteTail 之间的节点
                previous->next = node2DeleteTail->next;
                node2DeleteTail->next->previous = previous;

                // 更新指针
                previous = cur;
                cur = previous->next;
            }
        }
        else
        {
            previous = cur;
            cur = cur->next;
        }
    }

    return head;
}

// 递归删除
// ListNode* removeElements(ListNode* head, int val) {
    
//     // 当前节点为空
//     if (head == NULL) {
//         return NULL;
//     }
    
//     // 尾巴节点为空
//     if (head->val == val && head->next == NULL) {
//         return NULL;
//     }
    
//     head->next = removeElements(head->next, val);
    
//     if (head->val == val) {
//         if (head->next != NULL) {
//             head->val = head->next->val;
//             head->next = head->next->next;
//         }else {
//             return head->next;
//         }
//     }
    
//     return head;
// }

Node * Node::removeAllValuesInElement(Node *head, int k){

    Node *cur = head;
    Node *previous = nullptr;
    Node *newHead = head;
    while (cur->next != nullptr)
    {
        // 删除节点
        if (cur->value == k)
        {
            if (cur == newHead)
            {
                // 如果是头结点
                newHead = newHead->next;   

                // 更新cur指针
                cur = cur->next;
                previous = nullptr;
            }
            else if(previous != nullptr) {

                // 非头结点，直接删除cur节点
                previous->next = cur->next;
                // 更新指针
                // previous = cur;
                cur = cur->next;
            }
        }
        else
        {
            previous = cur;
            cur = cur->next;
        }
    }
    
    return newHead;
}

// 将小于和大于给定值的节点划分到链表两侧
Node *Node::partitionLinkedList(Node *head, int k) {

    Node *smallerHeader = new Node(-1);
    Node *curSmallerHeader = smallerHeader;

    Node *greaterHeader = new Node(-1);
    Node *curGreaterHeader = greaterHeader;

    Node *euqalHeader = new Node(-1);
    Node *curEuqalHeader = euqalHeader;

    Node *cur = head;
    while (cur != nullptr)
    {
        if (cur->value == k)
        {
            curEuqalHeader->next = cur;
            curEuqalHeader = cur;
        }
        else if(cur->value > k)
        {
            curGreaterHeader->next = cur;
            curGreaterHeader = cur;
        }
        else if(cur->value < k)
        {
            curSmallerHeader->next = cur;
            curSmallerHeader = cur;
        }

        cur = cur->next;
    }
    
    // 清空右侧指针域
    curEuqalHeader->next = nullptr;
    curGreaterHeader->next = nullptr;

    // 拼凑节点
    if (euqalHeader->next != nullptr)
    {
        curSmallerHeader->next = euqalHeader->next;
        curEuqalHeader->next = greaterHeader->next;
    }
    else
    {
        curSmallerHeader->next = greaterHeader->next;
    }

    return smallerHeader->next;
}

// 将基数偶数的节点分在链表两侧
Node * Node::oddEvenLinkedList(Node *head) {

    Node *oddHeader = new Node(-1);
    Node *curOdd = oddHeader;
    Node *evenHeader = new Node(-1);
    Node *curEven = evenHeader;

    Node *cur = head;

    int idx = 1;
    while (cur != nullptr)
    {
        
        if (idx % 2 == 0)
        {
            // 偶数
            curEven->next = cur;
            curEven = cur;
        }
        else {
            // 奇数
            curOdd->next = cur;
            curOdd = cur;
        }
        
        idx ++;
        cur = cur->next;
    }
    
    curEven->next = nullptr;
    curOdd->next = nullptr;

    // 合并节点
    curOdd->next = evenHeader->next;

    return oddHeader->next;
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

// 递归反向打印
void __debugPrintReversingly(Node * node, bool isHead = true) {

    if (node == nullptr)
    {
        //cout << endl;
        return;
    }
    
    __debugPrintReversingly(node->next, false);

    cout << (node->value);
    if (isHead == true)
    {
        cout << endl;
    }else {
        cout << "->";
    }
}

Node * Node::debugPrintReversingly() {

    Node *cur = this;
    __debugPrintReversingly(cur);
}