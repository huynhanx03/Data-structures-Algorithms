/*
 Problem: 657. Robot Return to Origin
 Language: cpp
 Runtime: 12 ms (10.72%)
 Memory: 8.1 MB (100.00%)
 Tags: String, Simulation
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        int d1=0,d2=0;
        for (int i=0;i<moves.size();++i)
        {
            if (moves[i]=='U') ++d1;
            if (moves[i]=='D') --d1;
            if (moves[i]=='R') ++d2;
            if (moves[i]=='L') --d2;
        }
        return (d1==0 && d2 == 0);
    }
};