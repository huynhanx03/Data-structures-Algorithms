/*
 Problem: 295. Find Median from Data Stream
 Language: cpp
 Runtime: 43 ms (98.15%)
 Memory: 124.9 MB (100.00%)
 Tags: Two Pointers, Design, Sorting, Heap (Priority Queue), Data Stream
*/
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
    MedianFinder() : sizeMaxHeap(0), sizeMinHeap(0) {}

    void addNum(int num) {
        if (sizeMaxHeap == 0 || num <= maxHeap[0]) {
            addMaxHeap(num);
        } else {
            addMinHeap(num);
        }

        if (sizeMaxHeap > sizeMinHeap + 1) {
            addMinHeap(removeMaxHeap());
        } else if (sizeMinHeap > sizeMaxHeap) {
            addMaxHeap(removeMinHeap());
        }
    }

    double findMedian() {
        if (sizeMaxHeap == sizeMinHeap) {
            return (maxHeap[0] + minHeap[0]) / 2.0;
        } else {
            return maxHeap[0];
        }
    }

private:
    vector<int> maxHeap;
    vector<int> minHeap;
    int sizeMaxHeap;
    int sizeMinHeap;

    void addMaxHeap(int num) {
        maxHeap.push_back(num);
        ++sizeMaxHeap;
        int i = sizeMaxHeap - 1;
        while (i > 0 && maxHeap[parent(i)] < maxHeap[i]) {
            swap(maxHeap[i], maxHeap[parent(i)]);
            i = parent(i);
        }
    }

    void addMinHeap(int num) {
        minHeap.push_back(num);
        ++sizeMinHeap;
        int i = sizeMinHeap - 1;
        while (i > 0 && minHeap[parent(i)] > minHeap[i]) {
            swap(minHeap[i], minHeap[parent(i)]);
            i = parent(i);
        }
    }

    int removeMaxHeap() {
        int top = maxHeap[0];
        swap(maxHeap[0], maxHeap[--sizeMaxHeap]);
        maxHeap.pop_back();
        heapifyMaxHeap(0);
        return top;
    }

    int removeMinHeap() {
        int top = minHeap[0];
        swap(minHeap[0], minHeap[--sizeMinHeap]);
        minHeap.pop_back();
        heapifyMinHeap(0);
        return top;
    }

    void heapifyMaxHeap(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < sizeMaxHeap && maxHeap[l] > maxHeap[largest]) {
            largest = l;
        }
        if (r < sizeMaxHeap && maxHeap[r] > maxHeap[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(maxHeap[i], maxHeap[largest]);
            heapifyMaxHeap(largest);
        }
    }

    void heapifyMinHeap(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < sizeMinHeap && minHeap[l] < minHeap[smallest]) {
            smallest = l;
        }
        if (r < sizeMinHeap && minHeap[r] < minHeap[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            swap(minHeap[i], minHeap[smallest]);
            heapifyMinHeap(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */