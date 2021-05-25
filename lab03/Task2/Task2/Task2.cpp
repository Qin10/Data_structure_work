#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


class MyTree
{
public:
    MyTree()
    {
        root = nullptr;
    }

    ~MyTree()
    {

    }

    bool isEmpty()
    {
        if (root == nullptr)
            return true;
        else
            return false;
    }

    void insert(int k)
    {
        insert(k, root);
    }

    bool contains(int k)
    {
        bool isContain = false;
        Node* temp = root;
        while (true)
        {
            if (temp == nullptr)
            {
                break;
            }
            else if (k == temp->content)
            {
                isContain = true;
                break;
            }
            else if (k < temp->content)
            {
                temp = temp->left;
            }
            else if (k > temp->content)
            {
                temp = temp->right;
            }
            else
                ;
        }
        return isContain;
    }

    int findMinValue()
    {
        if (root == nullptr)
        {
            return -1;
        }

        Node* temp = root;
        int min;
        while (temp != nullptr)
        {
            min = temp->content;
            temp = temp->left;
        }
        return min;
    }

    void printTree()
    {
        this->printTree(root);
    }

    void printTreePreorder()
    {
        this->printTreePreorder(root);
    }

private:
    struct Node
    {
        Node* left;
        Node* right;
        int content;

        Node(int theContent, Node* left, Node* right)
            : content{ theContent }, left{ left }, right{ right } { }
    };
    Node* root;

    void insert(int k, struct Node*& currentNode)
    {
        if (currentNode == nullptr)
            currentNode = new Node(k, nullptr, nullptr);
        else if (k < currentNode->content)
            insert(k, currentNode->left);
        else if (k > currentNode->content)
            insert(k, currentNode->right);
        else;
    }

    void printTree(struct Node* currentNode)
    {
        if (currentNode == nullptr)
            return;
        printTree(currentNode->left);
        cout << currentNode->content << " ";
        printTree(currentNode->right);
    }

    void printTreePreorder(struct Node* currentNode)
    {
        if (currentNode == nullptr)
            return;
        cout << currentNode->content << " ";
        printTreePreorder(currentNode->left);
        printTreePreorder(currentNode->right);
    }

};

int main()
{
    int n = 30;
    MyTree myTree;
    srand((unsigned)time(NULL));
    cout << "Insert the 30 random numbers..." << endl;
    for (int i = 0; i < n; i++)
    {
        myTree.insert((rand() % 1000));
    }
    cout << "Print in inorder:" << endl;
    myTree.printTree();
    cout << endl;
    cout << "Print in preorder:" << endl;
    myTree.printTreePreorder();
    cout << endl;
    cout << myTree.findMinValue() << endl;
}