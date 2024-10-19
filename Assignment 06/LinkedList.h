#pragma Once
#include "Node.h"


template <typename T>
class LinkedList {
    private:
    Node<T>* head;

    public:
    LinkedList() {
        this->head = nullptr;
    }

    void add(T data) {
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

    void printList() {
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

    void deleteNode(T key) {
        Node<T> *temp = head;
        Node<T> *prev = nullptr;


        if (temp != nullptr && temp->getData() == key) {
            head = temp->getNode();
            delete temp;
            return;
        }

        while (temp != nullptr && temp->getData() != key) {
            prev = temp;
            temp = temp->getNode();
        }


        if (temp == nullptr) return;

        prev->setNode(temp->getNode());
        delete temp;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};