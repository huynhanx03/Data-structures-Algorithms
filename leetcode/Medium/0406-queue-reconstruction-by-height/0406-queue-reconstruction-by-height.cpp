/*
 Problem: 406. Queue Reconstruction by Height
 Language: cpp
 Runtime: 19 ms (59.57%)
 Memory: 16.1 MB (61.44%)
 Tags: Array, Binary Indexed Tree, Segment Tree, Sorting
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        vector<vector<int>> ans;
        for (const auto& p : people) {
            ans.insert(ans.begin() + p[1], p);
        }
        
        return ans;
    }
};