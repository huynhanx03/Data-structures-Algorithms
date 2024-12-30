#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

    // Destructor
    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }
        Node* temp = front;
        int value = front->data;
        front = front->next;
        if (!front) rear = nullptr; // If the queue is empty
        delete temp;
        return value;
    }

    // Get the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Print the queue
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    QueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.print();

    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();

    queue.enqueue(40);
    queue.enqueue(50);
    queue.print();

    return 0;
}
