/*
 Problem: 3790. Fruits Into Baskets II
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 48.9 MB (50.07%)
 Tags: Array, Binary Search, Segment Tree, Simulation, Ordered Set
*/
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        if (n == 0 || baskets.size() == 0)
            return n; // All fruits are unplaced if no baskets

        vector<bool> used(baskets.size(), false);
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            int qty = fruits[i];
            if (qty == 0)
                continue; // No need to place zero quantity fruits

            bool placed = false;
            for (int j = 0; j < baskets.size(); ++j) {
                if (!used[j] && baskets[j] >= qty) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }

        return unplaced;
    }
};