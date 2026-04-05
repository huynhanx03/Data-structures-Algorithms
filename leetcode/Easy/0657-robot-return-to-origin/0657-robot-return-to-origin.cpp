/*
 Problem: 657. Robot Return to Origin
 Language: cpp
 Runtime: 7 ms (10.20%)
 Memory: 10.2 MB (95.43%)
 Tags: String, Simulation
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        
        for (char move : moves) {
            if (move == 'U') y++;
            else if (move == 'D') y--;
            else if (move == 'L') x--;
            else if (move == 'R') x++;
        }
        
        return x == 0 && y == 0;
    }
};