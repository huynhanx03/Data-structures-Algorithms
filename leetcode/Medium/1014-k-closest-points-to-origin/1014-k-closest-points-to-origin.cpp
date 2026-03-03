/*
 Problem: 1014. K Closest Points to Origin
 Language: cpp
 Runtime: 90 ms (29.61%)
 Memory: 78.2 MB (29.80%)
 Tags: Array, Math, Divide and Conquer, Geometry, Sorting, Heap (Priority Queue), Quickselect
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (auto& point : points) {
            int x = point[0], y = point[1];
            int distance = x * x + y * y; // We use the square of the distance to avoid floating-point operations.
            
            maxHeap.push({distance, point});
            
            if (maxHeap.size() > k) {
                maxHeap.pop(); // Remove the farthest point if the heap size exceeds k.
            }
        }
        
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};
