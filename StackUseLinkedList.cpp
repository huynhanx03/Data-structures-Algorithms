#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* top;

public:
    // Constructor
    StackLinkedList() : top(nullptr) {}

    // Destructor
    ~StackLinkedList() {
        while (!isEmpty())
            pop();
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No element to pop." << endl;
            return -1; // Sentinel value
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Sentinel value
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Print the stack
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackLinkedList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
