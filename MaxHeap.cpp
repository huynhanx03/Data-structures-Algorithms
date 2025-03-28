#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.size() == 0) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() {
        return heap.size() ? heap[0] : -1;
    }

    void printHeap() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    heap.insert(7);
    heap.insert(1);
    heap.insert(9);
    heap.insert(5);
    heap.insert(4);
    heap.insert(12);
    heap.insert(99);
    heap.insert(25);

    cout << "Heap elements: ";
    heap.printHeap();

    cout << "Maximum element: " << heap.getMax() << endl;

    heap.deleteMax();
    cout << "Heap after deleting max: ";
    heap.printHeap();

    return 0;
}
