#include <vector>
#include <string>

using namespace std;

class Robot {
private:
    int w, h;
    int perimeter;
    int pos;
    bool moved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h - 2);
        pos = 0;
        moved = false;
    }
    
    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
    }
    
    vector<int> getPos() {
        if (pos < w) {
            return {pos, 0};
        } else if (pos < w + h - 1) {
            return {w - 1, pos - (w - 1)};
        } else if (pos < 2 * w + h - 2) {
            return {w - 1 - (pos - (w + h - 2)), h - 1};
        } else {
            return {0, perimeter - pos};
        }
    }
    
    string getDir() {
        if (!moved) return "East";
        
        if (pos > 0 && pos < w) {
            return "East";
        } else if (pos >= w && pos < w + h - 1) {
            return "North";
        } else if (pos >= w + h - 1 && pos < 2 * w + h - 2) {
            return "West";
        } else {
            return "South";
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