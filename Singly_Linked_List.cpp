#include "bits/stdc++.h"

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() {
            head = nullptr;
        }

        void insertAtBeginning(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        void deleteAtBeginning() {
            if (head == nullptr) {
                return;
            }

            Node* temp = head;
            head = head->next;
            delete temp;
        }

    void deleteAtEnd() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        delete current;
    }

    void deleteValue(int x) {
        if (head == nullptr) {
            return;
        }

        if (head->data == x) {
            deleteAtBeginning();
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == x) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }    
};

int main() {

}