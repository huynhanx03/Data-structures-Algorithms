/*
 Problem: 906. Walking Robot Simulation
 Language: cpp
 Runtime: 14 ms (89.87%)
 Memory: 36.8 MB (91.47%)
 Tags: Array, Hash Table, Simulation
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> st;
        for (const auto& o : obstacles) {
            long long key = ((long long)o[0] << 32) | (unsigned int)o[1];
            st.insert(key);
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int x = 0, y = 0, dir = 0;
        int ans = 0;

        for (const auto& cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long key = ((long long)nx << 32) | (unsigned int)ny;
                    if (st.count(key)) break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};