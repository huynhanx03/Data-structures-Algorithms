class RollingHash {
private:
    unsigned long long MOD = (1ULL << 61) - 1; 
    int base;
    vector<unsigned long long> pow;
    vector<unsigned long long> pref;

    unsigned long long add(unsigned long long a, unsigned long long b) {
        return (a += b) < MOD ? a : a - MOD;
    }

    unsigned long long sub(unsigned long long a, unsigned long long b) {
        return (a -= b) < MOD ? a : a + MOD;
    }

    unsigned long long mul(unsigned long long a, unsigned long long b) {
        unsigned long long l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
        unsigned long long l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        unsigned long long ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & MOD) + (ret >> 61);
        ret = (ret & MOD) + (ret >> 61);
        return ret - 1;
    }

public:
    RollingHash(const string& s, int seedBase = 33) {
        this->base = seedBase;
        pref.assign(s.size() + 1, 0);
        pow.push_back(1);

        while (pow.size() <= s.size()) {
            pow.push_back(mul(pow.back(), base));
        }

        for (int i = 0; i < (int)s.size(); ++i) {
            pref[i + 1] = add(mul(pref[i], base), s[i]);
        }
    }

    unsigned long long getHash(int pos, int len) {
        return sub(pref[pos + len], mul(pref[pos], pow[len]));
    }
};