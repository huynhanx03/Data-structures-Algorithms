#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<long long> bits;

    inline int lowbit(int i) const {
        return i & -i;
    }

public:
    FenwickTree(int n) : bits(n + 1, 0) {}

    void update(int i, long long x) {
        while (i < bits.size()) {
            bits[i] += x;
            i += lowbit(i);
        }
    }

    long long query(int i) const {
        long long sum = 0;
        while (i > 0) {
            sum += bits[i];
            i -= lowbit(i);
        }
        return sum;
    }

    long long queryRange(int l, int r) const {
        return query(r) - query(l - 1);
    }
};
