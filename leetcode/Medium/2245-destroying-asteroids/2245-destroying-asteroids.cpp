/*
 Problem: 2245. Destroying Asteroids
 Language: cpp
 Runtime: 23 ms (86.89%)
 Memory: 106.6 MB (83.03%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long s = mass;

        for (const auto& x : asteroids) {
            if (s >= x) {
                s += x;
            } else return false;
        }

        return true;
    }
};