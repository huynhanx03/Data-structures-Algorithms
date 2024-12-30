#include <iostream>
#include <list>
using namespace std;

class HashTableChaining {
private:
    int capacity;                   // Size of the hash table
    list<int>* table;               // Array of linked lists

    // Hash function
    int hashFunction(int key) {
        return key % capacity;      // Maps the key to an index
    }

public:
    // Constructor
    HashTableChaining(int size) {
        capacity = size;
        table = new list<int>[capacity];
    }

    // Destructor
    ~HashTableChaining() {
        delete[] table;
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);  // Add the key to the linked list
    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);    // Remove the key from the linked list
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        for (auto& element : table[index]) {
            if (element == key)
                return true;
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            for (auto& element : table[i])
                cout << element << " ";
            cout << endl;
        }
    }
};

int main() {
    HashTableChaining hashTable(7); // Create a hash table with size 7

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
