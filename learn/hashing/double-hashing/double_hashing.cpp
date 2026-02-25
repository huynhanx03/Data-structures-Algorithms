class DoubleHash {
private:
    long long n;
    vector<long long> h1;
    vector<long long> h2;
    vector<long long> pow1;
    vector<long long> pow2;
    
    const long long p1 = 31;
    const long long m1 = 1e9 + 7;
    const long long p2 = 53;
    const long long m2 = 1e9 + 9;

public:
    DoubleHash(const string& s) {
        n = s.size();
        
        pow1.resize(n + 1);
        pow2.resize(n + 1);
        pow1[0] = 1;
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i - 1] * p1) % m1;
            pow2[i] = (pow2[i - 1] * p2) % m2;
        }

        h1.resize(n + 1);
        h2.resize(n + 1);
        
        if (n > 0) {
            h1[0] = ((s[0] - 'a' + 1) * pow1[0]) % m1;
            h2[0] = ((s[0] - 'a' + 1) * pow2[0]) % m2;
        }
        
        for (int i = 1; i < n; i++) {
            h1[i] = (h1[i - 1] + pow1[i] * (s[i] - 'a' + 1)) % m1;
            h2[i] = (h2[i - 1] + pow2[i] * (s[i] - 'a' + 1)) % m2;
        }
    }

    pair<long long, long long> getHash(int l, int r) {
        if (l < 0 || r >= n || l > r) return {0, 0};
        
        long long fi = h1[r];
        if (l >= 1)
            fi = (fi - h1[l - 1] + m1) % m1;
        fi = (fi * pow1[n - r - 1]) % m1;
        
        long long se = h2[r];
        if (l >= 1)
            se = (se - h2[l - 1] + m2) % m2;
        se = (se * pow2[n - r - 1]) % m2;
        
        return {fi, se};
    }
};
