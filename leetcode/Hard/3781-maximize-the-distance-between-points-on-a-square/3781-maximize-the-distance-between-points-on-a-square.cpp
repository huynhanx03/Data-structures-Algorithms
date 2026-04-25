/*
 Problem: 3781. Maximize the Distance Between Points on a Square
 Language: cpp
 Runtime: 76 ms (24.72%)
 Memory: 92.5 MB (6.74%)
 Tags: Array, Math, Binary Search, Geometry, Sorting
*/
class Solution {
private:
    struct Seq {
        int sx, sy, ex, ey, len;
    };

    bool check(vector<pair<int, int>>& a, int k, int d) {
        deque<Seq> q;
        q.push_back({a[0].first, a[0].second, a[0].first, a[0].second, 1});

        int best = 1;

        for (int i = 1; i < a.size(); ++i) {
            auto [x, y] = a[i];

            int sx = x, sy = y, len = 1;

            while (!q.empty() && dist(x, y, q.front().ex, q.front().ey) >= d) {
                if (dist(x, y, q.front().sx, q.front().sy) >= d && q.front().len + 1 >= len) {
                    sx = q.front().sx;
                    sy = q.front().sy;
                    len = q.front().len + 1;
                    best = max(best, len);
                }
                q.pop_front();
            }

            q.push_back({sx, sy, x, y, len});
        }

        return best >= k;
    }

    int dist(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    vector<pair<int, int>> orderPoints(int side, vector<vector<int>>& points) {
        vector<pair<int, int>> left, top, right, bottom;

        for (auto& p : points) {
            int x = p[0], y = p[1];

            if (x == 0 && y > 0) left.push_back({x, y});
            else if (y == side && x > 0) top.push_back({x, y});
            else if (x == side && y < side) right.push_back({x, y});
            else bottom.push_back({x, y});
        }

        sort(left.begin(), left.end());
        sort(top.begin(), top.end());
        sort(right.rbegin(), right.rend());
        sort(bottom.rbegin(), bottom.rend());

        left.insert(left.end(), top.begin(), top.end());
        left.insert(left.end(), right.begin(), right.end());
        left.insert(left.end(), bottom.begin(), bottom.end());

        return left;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        auto a = orderPoints(side, points);

        int l = 0, r = side;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (check(a, k, m)) l = m;
            else r = m - 1;
        }

        return l;
    }
};