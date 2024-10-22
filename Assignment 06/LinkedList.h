#pragma once
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    // Stack Operations
    void Push(T data) {
        Node<T> *newNode = new Node<T>(data);

        if (!head) {
            head = newNode;
        } else {
            Node<T> *temp = head;
            while (temp->getNode() != nullptr) {
                temp = temp->getNode();
            }
            temp->setNode(newNode);
        }
    }

    T Pop() {
        if (!head) {
            cout << "Stack is empty, nothing to pop." << endl;
            return T(); 
        }

        if (head->getNode() == nullptr) {  
            T data = head->getData();
            delete head;
            head = nullptr;
            return data;
        }

        Node<T> *temp = head;
        Node<T> *prev = nullptr;

        while (temp->getNode() != nullptr) {
            prev = temp;
            temp = temp->getNode();
        }

        T data = temp->getData();
        delete temp;

        if (prev) {
            prev->setNode(nullptr);
        }

        return data;
    }

    void DisplayStack() {
        if (!head) {
            cout << "The stack is empty." << endl;
            return;
        }

        Node<T> *temp = head;
        while (temp != nullptr) {
            cout << " " << temp->getData() << "\n ^\n |\n";
            temp = temp->getNode();
        }
        cout << "NULL" << endl;
    }

    // Queue Operations
    void Insert(T data) {
        Push(data);
    }

    T Remove() {
        if (!head) {
            cout << "Queue is empty, nothing to remove." << endl;
            return T(); 
        }

        Node<T> *temp = head;
        T data = head->getData();
        head = head->getNode();
        delete temp;
        return data;
    }

    void DisplayQueue() {
        printListQueue();
    }

    void InsertPQ(T data) {
        Node<T> *newNode = new Node<T>(data);

        if (!head || head->getData() > data) {
            newNode->setNode(head);
            head = newNode;
        } else {
            Node<T> *temp = head;
            while (temp->getNode() && temp->getNode()->getData() <= data) {
                temp = temp->getNode();
            }
            newNode->setNode(temp->getNode());
            temp->setNode(newNode);
        }
    }

    T RemovePQ() {
        return Remove();
    }

    void DisplayPQ() {
        printListQueue();
    }

    void printListQueue() {
        Node<T> *temp = head;
        if (!temp) {
            cout << "The list is empty." << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->getData() << " -> ";
            temp = temp->getNode();
        }
        cout << "NULL" << endl;
    }

    void printListReverse(Node<T>* node) {
        if (node == nullptr) {
            return;
        }

        printListReverse(node->getNode());
        cout << endl << " " << node->getData() << "\n ^\n |\n";
    }

    void printList() {
        if (!head) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "NULL" << "\n ^\n |\n";
        printListReverse(head);
    }

    bool isEmpty() {
        return head == nullptr;
    }
   
    void Clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->getNode();
            delete temp; 
        }
        cout << "\nList cleared!" << endl;
    }
};

