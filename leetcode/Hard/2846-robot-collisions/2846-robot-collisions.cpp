/*
 Problem: 2846. Robot Collisions
 Language: cpp
 Runtime: 74 ms (25.75%)
 Memory: 220 MB (24.35%)
 Tags: Array, Stack, Sorting, Simulation
*/
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<array<int,4>> a;

        for (int i = 0; i < n; ++i)
            a.push_back({positions[i], healths[i], directions[i], i});

        sort(a.begin(), a.end());

        stack<int> st;

        for (int i = 0; i < n; ++i) {
            if (a[i][2] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && a[i][1] > 0) {
                    int j = st.top();

                    if (a[j][1] < a[i][1]) {
                        a[i][1]--;
                        a[j][1] = 0;
                        st.pop();
                    } else if (a[j][1] > a[i][1]) {
                        a[j][1]--;
                        a[i][1] = 0;
                        break;
                    } else {
                        a[j][1] = 0;
                        a[i][1] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<pair<int,int>> res;
        for (const auto& x : a)
            if (x[1] > 0)
                res.push_back({x[3], x[1]});

        sort(res.begin(), res.end());

        vector<int> ans;
        for (const auto& p : res)
            ans.push_back(p.second);

        return ans;
    }
};