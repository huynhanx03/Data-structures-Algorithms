#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void deleteNode(int value) {
        if (!tail) return;

        Node* curr = tail->next;
        Node* prev = tail;

        do {
            if (curr->data == value) {
                if (curr == tail) {
                    if (curr == tail->next) { // Only one node
                        delete curr;
                        tail = nullptr;
                    } else {
                        prev->next = curr->next;
                        tail = prev;
                        delete curr;
                    }
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void printList() const {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(Back to head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtHead(10);
    cll.insertAtTail(20);
    cll.insertAtTail(30);
    cll.printList();
    cll.deleteNode(20);
    cll.printList();
    return 0;
}
