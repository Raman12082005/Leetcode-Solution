class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xclosest = max(x1, min(xCenter, x2));
        int yclosest = max(y1, min(yCenter, y2));
        int dx = xCenter - xclosest;
        int dy = yCenter - yclosest;
        if(1LL*r*r >= 1LL*dx*dx + 1LL*dy*dy) return true;
        return false;
    }
};