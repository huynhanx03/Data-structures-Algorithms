#include <iostream>
#include <vector>
using namespace std;

class HashTableLinearProbing {
private:
    vector<int> table;             // Hash table
    vector<bool> isOccupied;       // Array to track occupied slots
    int capacity;

    // Hash function
    int hashFunction(int key) {
        return key % capacity;     // Maps the key to an index
    }

public:
    // Constructor
    HashTableLinearProbing(int size) : capacity(size), table(size, -1), isOccupied(size, false) {}

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (isOccupied[index]) { // Find the next available slot
            index = (index + 1) % capacity; // Linear probing
            if (index == originalIndex) {   // If the table is full
                cout << "Hash table is full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = key;
        isOccupied[index] = true;
    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (isOccupied[index]) {
            if (table[index] == key) {
                table[index] = -1;       // Mark the slot as empty
                isOccupied[index] = false;
                return;
            }
            index = (index + 1) % capacity; // Linear probing
            if (index == originalIndex) break;
        }

        cout << "Key " << key << " not found!" << endl;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (isOccupied[index]) {
            if (table[index] == key)
                return true;
            index = (index + 1) % capacity; // Linear probing
            if (index == originalIndex) break;
        }

        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (isOccupied[i])
                cout << "Index " << i << ": " << table[i] << endl;
            else
                cout << "Index " << i << ": Empty" << endl;
        }
    }
};

int main() {
    HashTableLinearProbing hashTable(7); // Create a hash table with size 7

    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(15);
    hashTable.insert(7);

    hashTable.display();

    cout << "Search for 15: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;
    hashTable.remove(15);
    cout << "After removing 15:" << endl;
    hashTable.display();

    return 0;
}
