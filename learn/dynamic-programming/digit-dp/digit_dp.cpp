class DigitDP {
private:
    string s;
    vector<vector<long long>> memo;

    long long solve(int id, bool flag) {
        if (id == s.size()) {
            return 1; // Base case: successfully formed a valid number
        }
        
        if (memo[id][flag] != -1) return memo[id][flag];
        
        long long ans = 0;
        int limit = flag ? (s[id] - '0') : 9;

        for (int i = 0; i <= limit; ++i) {
            bool newflag = flag && (i == limit);
            ans += solve(id + 1, newflag);
        }

        return memo[id][flag] = ans;
    }

public:
    DigitDP() {}

    // Calculate the number of valid values in range [0, target]
    long long countValid(long long target) {
        if (target < 0) return 0;
        s = to_string(target);
        memo.assign(s.size(), vector<long long>(2, -1));
        return solve(0, true);
    }
    
    // Calculate the number of valid values in range [L, R]
    long long countInRange(long long L, long long R) {
        return countValid(R) - countValid(L - 1);
    }
};