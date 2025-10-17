#include <iostream>
using namespace std;

class QueueArray {
private:
    int* arr;
    int front, rear, capacity, size;

public:
    // Constructor
    QueueArray(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~QueueArray() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular array
        arr[rear] = value;
        size++;
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity; // Circular array
        size--;
        return value;
    }

    // Get the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Print the queue
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    QueueArray queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.print();

    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();

    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.print();

    queue.enqueue(70); // Should show "Queue is full"

    return 0;
}
