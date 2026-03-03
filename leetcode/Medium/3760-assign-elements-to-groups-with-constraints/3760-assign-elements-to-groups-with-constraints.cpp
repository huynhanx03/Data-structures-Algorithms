/*
 Problem: 3760. Assign Elements to Groups with Constraints
 Language: cpp
 Runtime: 1371 ms (12.40%)
 Memory: 259.9 MB (33.88%)
 Tags: Array, Hash Table
*/
class Solution {
private:
    map<int, int> mp;
    vector<int> ans;
    int oo = 1e9;
    
    void divi(int v) {
        int res = oo;
        
        for (int i = 1; i * i <= v; ++i) {
            if (v % i == 0) {
                if (mp.find(i) != mp.end())    
                    res = min(res, mp[i]);
                
                if (i != v / i && mp.find(v / i) != mp.end())
                     res = min(res, mp[v / i]);
            }
        }
        
        if (res == oo) ans.push_back(-1);
        else ans.push_back(res);
    }    
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int szgr = groups.size();
        int sze = elements.size();
        
        // min index
        for (int i = 0; i < sze; ++i) {
            if (mp.find(elements[i]) == mp.end()) mp[elements[i]] = i;
        }
        
        for (int i = 0; i < szgr; ++i)
            divi(groups[i]);
        
        return ans;
    }
};