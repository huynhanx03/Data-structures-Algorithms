/*
 Problem: 2251. Number of Ways to Divide a Long Corridor
 Language: cpp
 Runtime: 27 ms (51.31%)
 Memory: 58.9 MB (12.78%)
 Tags: Math, String, Dynamic Programming
*/
class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        
        vector<int> seats;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seats.push_back(i);
            }
        }
        
        if (seats.size() == 0 || seats.size() % 2 != 0) return 0;
        
        long long sum = 1;
        
        for (int i = 2; i < seats.size(); i += 2) {
            int prevSecondSeat = seats[i - 1];
            int currentFirstSeat = seats[i];
            
            int plantsBetween = currentFirstSeat - prevSecondSeat;
            
            sum = (sum * plantsBetween) % MOD;
        }
        
        return sum;
    }
};