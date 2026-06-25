class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        // base case
        if( n <= 2) return n;

        int cnt = 2;
        for(int i=0; i<n-1; i++){
            map<pair<int, int>, int> mpp;
            for(int j=i+1; j<n; j++){
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                // normalise it
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                if(dx < 0){
                    dx = -dx;
                    dy = -dy;
                }

                // if slope is notdefined
                if(dx == 0) dy = 1;
                // if slope is 0
                if(dy == 0) dx = 1;

                mpp[{dx, dy}]++;
                cnt = max(cnt, mpp[{dx, dy}]+1);
            }
        }
        return cnt;
    }
};