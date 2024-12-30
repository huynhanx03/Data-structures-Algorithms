#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head) head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (temp) {
            if (temp->next) temp->next->prev = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            delete temp;
        }
    }

    void printList() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.printList();
    dll.deleteNode(20);
    dll.printList();
    return 0;
}
