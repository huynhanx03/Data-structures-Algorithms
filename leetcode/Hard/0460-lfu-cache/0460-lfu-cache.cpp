/*
 Problem: 460. LFU Cache
 Language: cpp
 Runtime: 99 ms (73.95%)
 Memory: 184.8 MB (86.18%)
 Tags: Hash Table, Linked List, Design, Doubly-Linked List
*/
struct Node {
    int key, value, freq;
    Node *prev, *next;
    Node(int k, int v): key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
};

struct DLinkedList {
    Node *head, *tail;
    int size;
    DLinkedList() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFirst(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    Node* removeLast() {
        if (size == 0) return nullptr;
        Node* node = tail->prev;
        remove(node);
        return node;
    }
};

class LFUCache {
    int capacity, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLinkedList*> freqList;

    void update(Node* node) {
        int f = node->freq;
        freqList[f]->remove(node);
        if (f == minFreq && freqList[f]->size == 0) minFreq++;
        node->freq++;
        if (!freqList.count(node->freq)) freqList[node->freq] = new DLinkedList();
        freqList[node->freq]->addFirst(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!keyNode.count(key)) return -1;
        Node* node = keyNode[key];
        update(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyNode.count(key)) {
            Node* node = keyNode[key];
            node->value = value;
            update(node);
        } else {
            if ((int)keyNode.size() == capacity) {
                Node* del = freqList[minFreq]->removeLast();
                keyNode.erase(del->key);
                delete del;
            }
            Node* node = new Node(key, value);
            keyNode[key] = node;
            minFreq = 1;
            if (!freqList.count(1)) freqList[1] = new DLinkedList();
            freqList[1]->addFirst(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */