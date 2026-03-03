/*
 Problem: 1023. Time Based Key-Value Store
 Language: cpp
 Runtime: 36 ms (90.18%)
 Memory: 136.6 MB (81.66%)
 Tags: Hash Table, String, Binary Search, Design
*/
class TimeMap {
public:
    TimeMap() {
        // Constructor
    }

    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return "";
        }

        const auto& records = data[key];
        auto it = upper_bound(records.begin(), records.end(), timestamp, 
                              [](int ts, const pair<int, string>& record) {
                                  return ts < record.first;
                              });

        if (it == records.begin()) {
            return "";
        }

        return prev(it)->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */