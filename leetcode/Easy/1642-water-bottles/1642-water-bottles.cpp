/*
 Problem: 1642. Water Bottles
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.7 MB (78.78%)
 Tags: Math, Simulation
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newFull = empty / numExchange;
            totalDrunk += newFull;
            empty = empty % numExchange + newFull;
        }

        return totalDrunk;
    }
};
