struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head) {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }
        if (temp) {
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            delete temp;
        }
    }
};
