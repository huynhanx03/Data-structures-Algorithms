/*
 Problem: 3933. Minimum Jumps to Reach End via Prime Teleportation
 Language: cpp
 Runtime: 425 ms (61.03%)
 Memory: 334.7 MB (38.35%)
 Tags: Array, Hash Table, Math, Breadth-First Search, Number Theory
*/
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; ++i) {
            spf[i] = i;
        }

        for (long long i = 2; i * i <= mx; ++i) {
            if (spf[i] != i) {
                continue;
            }

            for (long long j = i * i; j <= mx; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }

        auto isPrime = [&](int x) {
            return x >= 2 && spf[x] == x;
        };

        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                pos[p].push_back(i);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        vector<int> dist(n, -1);

        queue<int> q;

        auto push = [&](int idx, int d) {
            if (idx < 0 || idx >= n) {
                return;
            }

            if (dist[idx] != -1) {
                return;
            }

            dist[idx] = d;
            q.push(idx);
        };

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) {
                return dist[i];
            }

            push(i - 1, dist[i] + 1);
            push(i + 1, dist[i] + 1);

            if (isPrime(nums[i])) {
                int p = nums[i];

                for (const int& j : pos[p]) {
                    push(j, dist[i] + 1);
                }

                pos[p].clear();
            }
        }

        return -1;
    }
};