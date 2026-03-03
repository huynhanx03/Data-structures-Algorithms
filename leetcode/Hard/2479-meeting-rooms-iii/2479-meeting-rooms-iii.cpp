/*
 Problem: 2479. Meeting Rooms III
 Language: cpp
 Runtime: 59 ms (97.54%)
 Memory: 98.3 MB (91.40%)
 Tags: Array, Hash Table, Sorting, Heap (Priority Queue), Simulation
*/
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> usedRooms;
        vector<long long> count(n, 0);
        
        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
            long long duration = end - start;
            
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                freeRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }
            
            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                usedRooms.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({freeTime + duration, room});
                count[room]++;
            }
        }
        
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) ans = i;
        }
        return ans;
    }
};
