/*
 Problem: 969. Number of Recent Calls
 Language: cpp
 Runtime: 19 ms (46.10%)
 Memory: 64.3 MB (36.78%)
 Tags: Design, Queue, Data Stream
*/
class RecentCounter {
private:
    queue<int> qu;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        qu.push(t);
        while (!qu.empty() && qu.front() < t - 3000) qu.pop();
        return qu.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */