/*
 Problem: 2317. Count Collisions on a Road
 Language: cpp
 Runtime: 3 ms (94.06%)
 Memory: 19.3 MB (32.08%)
 Tags: String, Stack, Simulation
*/
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        while (left < n && directions[left] == 'L') left++;
        while (right >= 0 && directions[right] == 'R') right--;

        int collisions = 0;
        for (int i = left; i <= right; i++)
            if (directions[i] != 'S') collisions++;

        return collisions;
    }
};