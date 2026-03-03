/*
 Problem: 3827. Implement Router
 Language: cpp
 Runtime: 282 ms (44.63%)
 Memory: 429.4 MB (81.31%)
 Tags: Array, Hash Table, Binary Search, Design, Queue, Ordered Set
*/
class Router {
private:
    struct Packet {
        int s, d, t;
    };

    int memory;
    queue<Packet> qu;
    unordered_set<string> used;
    unordered_map<int, vector<int>> destTimes;

    string key(int s, int d, int t) {
        return to_string(s) + "." + to_string(d) + "." + to_string(t);
    }

public:
    Router(int m) : memory(m) {}

    bool addPacket(int s, int d, int t) {
        string k = key(s,d,t);
        if (used.count(k)) return false;

        if ((int)qu.size() == memory) {
            auto old = qu.front(); qu.pop();
            used.erase(key(old.s, old.d, old.t));
            auto &vec = destTimes[old.d];
            vec.erase(lower_bound(vec.begin(), vec.end(), old.t));
        }

        qu.push({s,d,t});
        used.insert(k);
        destTimes[d].push_back(t);
        return true;
    }

    vector<int> forwardPacket() {
        if (qu.empty()) return {};
        auto p = qu.front(); qu.pop();
        used.erase(key(p.s,p.d,p.t));
        auto &vec = destTimes[p.d];
        vec.erase(lower_bound(vec.begin(), vec.end(), p.t));
        return {p.s,p.d,p.t};
    }

    int getCount(int d, int l, int r) {
        auto &vec = destTimes[d];
        return upper_bound(vec.begin(), vec.end(), r) - 
               lower_bound(vec.begin(), vec.end(), l);
    }
};
