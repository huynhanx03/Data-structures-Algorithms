/*
 Problem: 3548. Find the Count of Good Integers
 Language: cpp
 Runtime: 587 ms (35.23%)
 Memory: 106.5 MB (22.73%)
 Tags: Hash Table, Math, Combinatorics, Enumeration
*/
class Solution {
public:
    vector<long long> generatePalindromes(int n) {
        vector<long long> res;
        int half = (n + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);
        for (int i = start; i < end; ++i) {
            string s = to_string(i);
            string rev = s;
            if (n % 2 == 1)
                rev.pop_back();
            reverse(rev.begin(), rev.end());
            string full = s + rev;
            res.push_back(stoll(full));
        }
        return res;
    }

    long long factorial(int n) {
        static vector<long long> fact(11, 0); // n <= 10
        if (fact[0] == 0) {
            fact[0] = 1;
            for (int i = 1; i <= 10; ++i)
                fact[i] = fact[i - 1] * i;
        }
        return fact[n];
    }

    long long countPermutations(const string& digits) {
        map<char, int> freq;
        for (char c : digits)
            freq[c]++;

        long long total = 0;

        for (char first = '1'; first <= '9'; ++first) {
            if (freq[first] == 0)
                continue;

            freq[first]--;
            long long denom = 1;
            int remaining = digits.size() - 1;
            for (auto& [ch, count] : freq)
                denom *= factorial(count);

            total += factorial(remaining) / denom;
            freq[first]++;
        }

        return total;
    }

    long long countGoodIntegers(int n, int k) {
        unordered_set<string> validDigitSets;

        vector<long long> pals = generatePalindromes(n);
        for (long long pal : pals) {
            if (pal % k == 0) {
                string s = to_string(pal);
                sort(s.begin(), s.end());
                validDigitSets.insert(s);
            }
        }

        long long total = 0;
        for (const string& digitSet : validDigitSets) {
            total += countPermutations(digitSet);
        }

        return total;
    }
};
