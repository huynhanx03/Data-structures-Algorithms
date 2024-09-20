#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long ull;

int gen_base(int before, int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed ^ ull(new ull));
    std::uniform_int_distribution<int> dist(before+2, after-1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
}

class HashTable {
private:
    const int MOD = 4000277;
    const int step;
    vector <ull> data;

public:
    HashTable(): step(gen_base(MOD / 10, MOD)) {
        for (auto& it : data) it = 0;
        data.resize(MOD);
    }

    int get_hash(ull value) const {
        return int((value + step) % MOD);
    }

    void insert(ull value) {
        int hash = get_hash(value);
        while (1) {
            if (data[hash] == value) {
                return;
            }

            if (data[hash] == 0) {
                data[hash] = value;
                return;
            }

            hash += step;

            if (hash >= MOD) {
                hash -= MOD;
            }
        }
    }

    bool search(ull value) const {
        int hash = get_hash(value);
        while (1) {
            if (data[hash] == value) {
                return 1;
            }

            if (data[hash] == 0) {
                break;
            }

            hash += step;

            if (hash >= MOD) {
                hash -= MOD;
            } 
        }

        return 0;
    }
};

class PolyHash {
private:
    const ull MOD = (ull(1) << 61) - 1; // prime mod of hashing
    int base;                           // odd base of hashing
    vector <ull> pow;                   // powers of base modulo mod
    vector <ull> pref;                  // polynomial hash on prefix
public:
    PolyHash(): base(33)
    {
        pow.clear();
        pref.clear();
    }

    ull add (ull a, const ull& b) const {
        // Calculate (a + b) % mod, 0 <= a < mod, 0 <= b < mod
        return (a += b) < MOD ? a : a - MOD;
    }

    ull sub (ull a, const ull& b) const {
        // Calculate (a - b) % mod, 0 <= a < mod, 0 <= b < mod
        return (a -= b) < MOD ? a : a + MOD;
    }

    ull mul (const ull& a, const ull& b) const {
        // Calculate (a * b) % mod, 0 <= a < mod, 0 <= b < mod
        ull l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
        ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
        ull ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & MOD) + (ret >> 61);
        ret = (ret & MOD) + (ret >> 61);
        return ret-1;
    }

    PolyHash(const string& s) {
        this->base = gen_base(256, 1e9 + 123);
        
        pref.assign(s.size() + 1u, 0);
        
        pow.push_back(1);
        // Pre-calculate powers of base:
        while (pow.size() <= s.size()) {
            pow.push_back(this->mul(pow.back(), base));
        }

        // Calculate polinomial hash on prefix:
        for (int i = 0; i < (int)s.size(); ++i) {
            pref[i+1] = this->add(this->mul(pref[i], base), s[i]);
        }
    }

    ull operator() (const int& pos, const int& len) const {
        return this->sub(pref[pos+len], this->mul(pref[pos], pow[len]));
    }
};

int main() {
    string s;

    getline(cin, s);

    PolyHash hash_s(s);
}