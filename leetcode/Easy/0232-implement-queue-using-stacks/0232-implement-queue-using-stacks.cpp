/*
 Problem: 232. Implement Queue using Stacks
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.5 MB (99.81%)
 Tags: Stack, Design, Queue
*/
class MyQueue {
private:
    struct Node {
        int val;
        Node* next;

        Node(int value) : val(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
public:
    MyQueue() : front(nullptr), rear(nullptr) {}

    void push(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop() {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        int value = front->val;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    int peek() {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        return front->val;
    }

    bool empty() {
        return front == nullptr;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */