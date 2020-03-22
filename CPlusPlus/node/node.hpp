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

