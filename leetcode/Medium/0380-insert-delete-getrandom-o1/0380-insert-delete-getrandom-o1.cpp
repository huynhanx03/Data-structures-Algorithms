/*
 Problem: 380. Insert Delete GetRandom O(1)
 Language: cpp
 Runtime: 227 ms (5.05%)
 Memory: 103.1 MB (99.87%)
 Tags: Array, Hash Table, Math, Design, Randomized
*/
class RandomizedSet {
public:
    set<int> s;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        return s.insert(val).second;
    }
    
    bool remove(int val) {
        return s.erase(val) > 0;
    }
    
    int getRandom() {
        auto it = s.begin();
        std::advance(it, rand() % s.size());
        return *it;        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */