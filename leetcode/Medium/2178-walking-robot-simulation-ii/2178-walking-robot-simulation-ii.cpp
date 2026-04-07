/*
 Problem: 2178. Walking Robot Simulation II
 Language: cpp
 Runtime: 43 ms (32.76%)
 Memory: 127.3 MB (93.10%)
 Tags: Design, Simulation
*/
class Robot {
public:
    int w, h, per;
    int x = 0, y = 0;
    int dir = 0; // 0=E,1=N,2=W,3=S

    Robot(int width, int height) : w(width), h(height) {
        per = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        if (per == 0) return;

        num %= per;

        if (num == 0) {
            if (x == 0 && y == 0) dir = 3;
            return;
        }

        while (num > 0) {
            int move = 0;

            if (dir == 0) move = min(num, w - 1 - x);
            else if (dir == 1) move = min(num, h - 1 - y);
            else if (dir == 2) move = min(num, x);
            else move = min(num, y);

            if (dir == 0) x += move;
            else if (dir == 1) y += move;
            else if (dir == 2) x -= move;
            else y -= move;

            num -= move;

            if (num > 0) dir = (dir + 1) % 4;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        switch (dir) {
            case 0: return "East";
            case 1: return "North";
            case 2: return "West";
            default: return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */