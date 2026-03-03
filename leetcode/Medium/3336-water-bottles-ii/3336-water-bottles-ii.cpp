/*
 Problem: 3336. Water Bottles II
 Language: cpp
 Runtime: 5 ms (20.02%)
 Memory: 8.6 MB (14.99%)
 Tags: Math, Simulation
*/
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            ++totalDrunk;
            empty = empty - numExchange + 1;
            ++numExchange;
        }

        return totalDrunk;
    }
};