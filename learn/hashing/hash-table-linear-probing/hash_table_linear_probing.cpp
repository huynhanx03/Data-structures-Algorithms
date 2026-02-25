class HashTableLinearProbing {
private:
    vector<int> table;
    vector<bool> isOccupied;
    int capacity;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTableLinearProbing(int size) {
        capacity = size;
        table.assign(capacity, -1);
        isOccupied.assign(capacity, false);
    }

    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (isOccupied[index]) {
            index = (index + 1) % capacity;
            if (index == originalIndex) {
                return;
            }
        }

        table[index] = key;
        isOccupied[index] = true;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (isOccupied[index]) {
            if (table[index] == key) {
                table[index] = -1;
                isOccupied[index] = false;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) break;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (isOccupied[index]) {
            if (table[index] == key)
                return true;
            index = (index + 1) % capacity;
            if (index == originalIndex) break;
        }

        return false;
    }
};
