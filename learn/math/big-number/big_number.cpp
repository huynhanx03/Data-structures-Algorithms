class BigInt {
private:
    vector<int> digits;
    int base = 1e9;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

public:
    BigInt() {}

    BigInt(long long v) {
        if (v == 0) digits.push_back(0);
        while (v > 0) {
            digits.push_back(v % base);
            v /= base;
        }
    }

    BigInt(string s) {
        if (s.empty()) { digits.push_back(0); return; }
        while (s.size() % 9 != 0) s = '0' + s;
        for (int i = 0; i < s.size(); i += 9) {
            int v = 0;
            for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
            digits.insert(digits.begin(), v);
        }
        removeLeadingZeros();
    }

    BigInt operator+(const BigInt& b) const {
        BigInt res;
        int carry = 0;
        for (size_t i = 0; i < max(digits.size(), b.digits.size()) || carry; ++i) {
            if (i < digits.size()) carry += digits[i];
            if (i < b.digits.size()) carry += b.digits[i];
            res.digits.push_back(carry % base);
            carry /= base;
        }
        res.removeLeadingZeros();
        return res;
    }

    bool operator<(const BigInt& b) const {
        if (digits.size() != b.digits.size()) return digits.size() < b.digits.size();
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != b.digits[i]) return digits[i] < b.digits[i];
        }
        return false;
    }

    bool operator>(const BigInt& b) const { return b < *this; }
    bool operator==(const BigInt& b) const { return !(*this < b) && !(b < *this); }
    bool operator<=(const BigInt& b) const { return *this < b || *this == b; }
    
    // Extensibility to add subtraction, multiplication, and division as demonstrated
};