class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) return;
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) return -1;
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};
