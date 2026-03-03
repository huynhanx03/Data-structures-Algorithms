/*
 Problem: 502. IPO
 Language: cpp
 Runtime: 50 ms (99.56%)
 Memory: 135.7 MB (16.01%)
 Tags: Array, Greedy, Sorting, Heap (Priority Queue)
*/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;

        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        sort(projects.begin(), projects.end());

        int i = 0, n = projects.size();

        while (k--> 0) {
            while (i < n && projects[i].first <= w) {
                addHeap({projects[i].second, projects[i].first});
                ++i;
            }

            if (heap.empty()) break;

            auto key = heap[0];
            popHeap();

            w += key.first;
        }

        return w;
    }

private:
    vector<pair<int, int>> heap;

    bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }

    int sizeHeap;

    int parent(int i) { return (i - 1) >> 1; }

    int left(int i) { return (i << 1) + 1; }

    int right(int i) { return (i << 1) + 2; }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);

        int cur = i;

        if (l < sizeHeap && compare(heap[cur], heap[l])) {
            cur = l;
        }

        if (r < sizeHeap && compare(heap[cur], heap[r])) {
            cur = r;
        }

        if (cur != i) {
            swap(heap[cur], heap[i]);
            heapify(cur);
        }
    }

    void addHeap(pair<int, int> p) {
        heap.push_back(p);
        sizeHeap = heap.size();
        int i = sizeHeap - 1;
        while (i > 0 && compare(heap[parent(i)], heap[i])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void popHeap() {
        swap(heap[0], heap[--sizeHeap]);
        heapify(0);
        heap.pop_back();
    }
};