#pragma Once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

template <typename T>
class Node {
    private:
    T data;
    Node* nextNode;

    public:
   
    Node(T data) {
        this->data = data;
        this->nextNode = nullptr;
    }

    void setData(T data) {
        this->data = data;
    }

    T getData() {
        return this->data;
    }

    void setNode(Node* node) {
        this->nextNode = node;
    }

    Node* getNode() {
        return this->nextNode;
    }
};