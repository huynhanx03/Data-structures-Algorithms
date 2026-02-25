struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() : top(nullptr) {}

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
