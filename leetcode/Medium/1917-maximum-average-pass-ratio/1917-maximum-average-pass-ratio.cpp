/*
 Problem: 1917. Maximum Average Pass Ratio
 Language: cpp
 Runtime: 443 ms (15.26%)
 Memory: 92.2 MB (93.83%)
 Tags: Array, Greedy, Heap (Priority Queue)
*/
struct ClassInfo {
    int pass, total;
    double gain() const {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
};

struct Compare {
    bool operator()(const ClassInfo& a, const ClassInfo& b) {
        return a.gain() < b.gain();
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ClassInfo, vector<ClassInfo>, Compare> pq;
        
        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }

        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            top.pass++;
            top.total++;
            pq.push(top);
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto c = pq.top(); pq.pop();
            sum += (double)c.pass / c.total;
        }
        return sum / classes.size();
    }
};