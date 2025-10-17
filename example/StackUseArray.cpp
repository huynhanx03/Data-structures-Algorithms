#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No element to pop." << endl;
            return -1; // Sentinel value
        }
        return arr[top--];
    }

    // Peek the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Sentinel value
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Return the size of the stack
    int size() {
        return top + 1;
    }

    // Print the stack
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack stack(5);

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
