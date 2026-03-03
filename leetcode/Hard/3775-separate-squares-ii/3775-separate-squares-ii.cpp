/*
 Problem: 3775. Separate Squares II
 Language: cpp
 Runtime: 2777 ms (5.05%)
 Memory: 117.6 MB (80.84%)
 Tags: Array, Binary Search, Segment Tree, Sweep Line
*/
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<double,int,double,double>> events;
        for (auto& s : squares) {
            double x = s[0], y = s[1], l = s[2];
            events.push_back({y, 1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
        }

        sort(events.begin(), events.end());

        vector<pair<double,double>> xs;
        vector<tuple<double,double,double>> areas;
        double prevY = get<0>(events[0]), total = 0;

        auto unionLen = [&](vector<pair<double,double>>& v) {
            sort(v.begin(), v.end());
            double res = 0, end = -1e18;
            for (auto& [l, r] : v) {
                if (l > end) res += r - l;
                else if (r > end) res += r - end;
                end = max(end, r);
            }
            return res;
        };

        for (auto& [y, t, x1, x2] : events) {
            if (y > prevY && !xs.empty()) {
                double h = y - prevY;
                double w = unionLen(xs);
                areas.push_back({prevY, h, w});
                total += h * w;
            }
            if (t == 1) xs.push_back({x1, x2});
            else xs.erase(find(xs.begin(), xs.end(), make_pair(x1, x2)));
            prevY = y;
        }

        double half = total / 2, acc = 0;
        for (auto& [y, h, w] : areas) {
            if (acc + h * w >= half)
                return y + (half - acc) / w;
            acc += h * w;
        }
        return 0.0;
    }
};
