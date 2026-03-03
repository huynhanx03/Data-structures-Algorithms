/*
 Problem: 2463. Minimum Recolors to Get K Consecutive Black Blocks
 Language: cpp
 Runtime: 2 ms (7.73%)
 Memory: 8.3 MB (91.28%)
 Tags: String, Sliding Window
*/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0, ans = INT_MAX;
        
        for (int i = 0; i < blocks.size(); ++i) {
            if (i - k >= 0 && blocks[i - k] == 'B') --cnt;
            if (blocks[i] == 'B') ++cnt;
            
            ans = min(ans, k - cnt);
        }
        
        return ans;
    }
};