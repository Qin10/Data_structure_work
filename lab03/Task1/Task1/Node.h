#pragma once
class Node {
public:
    // A pointer to the left child node
    Node* left;
    // A pointer to the right child node
    Node* right;
    // An integer variable for the content
    int content;

public:
    explicit Node(int content) {
        left = nullptr;
        right = nullptr;
        this->content = content;
    }

    ~Node() = default;

    Node* getLeft() const {
        return left;
    }

    Node* getRight() const {
        return this->right;
    }

    void setLeft(Node* node) {
        left = node;
    }

    void setRight(Node* node) {
        right = node;
    }

    void setData(int data) {
        this->content = data;
    }
    int getdata() const {
        return content;
    }
};