class HashTableChaining {
private:
    int capacity;
    list<int>* table;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTableChaining(int size) {
        capacity = size;
        table = new list<int>[capacity];
    }

    ~HashTableChaining() {
        delete[] table;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (auto& element : table[index]) {
            if (element == key)
                return true;
        }
        return false;
    }
};
