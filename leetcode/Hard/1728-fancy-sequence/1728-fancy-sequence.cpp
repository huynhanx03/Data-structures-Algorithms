/*
 Problem: 1728. Fancy Sequence
 Language: cpp
 Runtime: 50 ms (93.43%)
 Memory: 192.4 MB (85.40%)
 Tags: Math, Design, Segment Tree
*/
class Fancy {
private:
    const long long MOD = 1e9 + 7;
    vector<long long> a;
    long long mul = 1, add = 0;

    long long modPow(long long x, long long n) {
        long long r = 1;
        while (n) {
            if (n & 1) r = r * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return r;
    }

    long long modInv(long long x) {
        return modPow(x, MOD - 2);
    }

public:
    Fancy() {
        
    }
    
    void append(int val) {
        long long x = (val - add) % MOD;
        if (x < 0) x += MOD;
        x = x * modInv(mul) % MOD;
        a.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= a.size()) return -1;
        return (a[idx] * mul % MOD + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */