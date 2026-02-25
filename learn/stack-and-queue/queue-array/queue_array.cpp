class QueueArray {
private:
    int* arr;
    int front, rear, capacity, size;

public:
    QueueArray(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~QueueArray() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};
