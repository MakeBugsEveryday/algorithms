#include <iostream>
#include<string>
using namespace std;

// Trie 节点
class TrieNode 
{

public:
    // 具体
    char val;
    // 标记节点，用来标记当前的节点是否为要存储节点的最后一个字节
    bool isEnd;
    // next数组
    TrieNode *next[26];
    
    TrieNode(char val);
    TrieNode();
    ~TrieNode();
};

TrieNode::TrieNode()
{
    // 初始化 Next 数组
    for (size_t i = 0; i < 26; i++)
    {
        next[i] = NULL;
    }
}

TrieNode::TrieNode(char val)
{
    this->val = val;
    // 初始化 Next 数组
    for (size_t i = 0; i < 26; i++)
    {
        next[i] = NULL;
    }
}

TrieNode::~TrieNode()
{
}

// Trie 
class Trie
{
public:
    /* 根节点，根节点为�? */
    TrieNode *root;

    Trie(/* args */);
    ~Trie();

    void insert(string word)
    {
        // 当前节点
        TrieNode *curNode = root;
        for (size_t i = 0; i < word.length(); i++)
        {
            // 获取当前字母所处的位置
            int num = word[i] - 'a';
            if (curNode->next[num] == NULL)
            {
                // 没有节点则创节点
                curNode->next[num] = new TrieNode(word[i]);
            } 

            // 节点往下走
            curNode = curNode->next[num];
        }
        
        // 将节点置为单词标节点
        curNode->isEnd = true;
    }

    // 查找
    bool search(string word) 
    {
        TrieNode *curNode = root;
        // 遍历
        for (size_t i = 0; i < word.length(); i++)
        {
            // 获取节点位置
            int num = word[i] - 'a';
            if (curNode->next[num] == NULL)
            {
                return false;
            }
            
            // 下一个节?
            curNode = curNode->next[num];
        }
        
        return curNode->isEnd;
    }

    // 是否为前缀
    bool hasPrefix(string word)
    {
        TrieNode *curNode = root;
        // 遍历
        for (size_t i = 0; i < word.length(); i++)
        {
            // 获取节点位置
            int num = word[i] - 'a';
            if (curNode->next[num] == NULL)
            {
                return false;
            }
            
            // 下一个节
            curNode = curNode->next[num];
        }
        
        // 节点不为空
        return true;
    }
};

Trie::Trie(/* args */)
{
    // 初始化根节点
    root = new TrieNode();
}

Trie::~Trie()
{
}


int main(int argc, char const *argv[])
{
    /* code */
    Trie tire;
    tire.insert("helloworld");
    tire.insert("fine");
    tire.insert("test");

    cout<<"search result :"<<tire.search("test")<<endl;
    cout<<"search result :"<<tire.search("test2")<<endl;
    cout<<"has prefix :"<<tire.hasPrefix("tes")<<endl;

    return 0;
}
