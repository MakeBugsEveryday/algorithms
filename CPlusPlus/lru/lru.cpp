#include<iostream>
#include"../node/node.hpp"

using namespace std;

class LRU
{
private:
    // 头结点
    Node *head;
    // 尾巴节点
    Node *tail;

public:
    LRU(/* args */);
    ~LRU();

    /* 将节点插入首部 */
    void insertNodeAtHead(Node *node);
    /* 将节点放入头结点 */
    void bringToHead(Node *node);
    /* 移除尾巴节点 */
    void removeTail();
    /* 移除节点 */
    void remove(Node *node);
    /* 移除所有节点 */
    void removeAll();
    /* 遍历打印所有节点 */
    void description();
};

LRU::LRU(/* args */)
{
}

LRU::~LRU()
{
}

void LRU::insertNodeAtHead(Node *node)
{
    // 已经是首部了，返回
    if (node == head)
    {
        return;
    }
    
    // 置空前节点
    node->previous = NULL;

    // 头结点为空，
    if (head == NULL)
    {
        head = tail = node;
        return;
    }
    
    // header 不为空
    head->previous = node;
    node->next = head;
    head = node; 
}

void LRU::removeTail()
{
    // tail为空
    if (tail == NULL)
    {
        return;
    }
    
    // 只有一个节点
    if (tail == head)
    {
        head = tail = NULL;
        return;
    }
    
    tail = tail->previous;
    tail->next = NULL;
}

void LRU::bringToHead(Node *node)
{
    if (head == node)
    {
        return;
    }

    // node为尾巴节点
    if (node == tail)
    {
        // 移除尾巴节点
        removeTail();
        // 插入头结点
        insertNodeAtHead(node);
        return;
    }
    
    // 断开节点
    node->previous->next = node->next;
    node->next->previous = node->previous;

    // 连接链表
    node->next = node->previous = NULL;
    insertNodeAtHead(node);
}

void LRU::remove(Node *node)
{
    if (node == head && node == tail)
    {
        head = tail = NULL;
        return;
    }

    if (node == head)
    {
        head = head->next;
        node->next = node->previous = NULL;
        return;
    }

    if (node == tail)
    {
        removeTail();
        return;
    }
    
    // 断开连接
    node->previous->next = node->next;
    node->next->previous = node->previous;
    
    // 清空
    node->next = node->previous = NULL;
}

void LRU::description() 
{
    Node *root = head;

    while (root)
    {
        cout << root->value << " ";
        root = root->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    LRU lru;
    lru.insertNodeAtHead(new Node(3));
    lru.insertNodeAtHead(new Node(2));
    lru.insertNodeAtHead(new Node(1));
    lru.description();
    
    lru.removeTail();
    lru.description();

    return 0;
}
