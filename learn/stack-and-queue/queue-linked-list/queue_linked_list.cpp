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
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) return -1;
        Node* temp = front;
        int value = front->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }
};
