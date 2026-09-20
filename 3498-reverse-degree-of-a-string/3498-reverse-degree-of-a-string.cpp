class Solution {
public:
    int reverseDegree(string str) {
        int n = str.size();
        int ans = 0;
        for(int i=1; i<=n; i++){
            char ch = str[i-1];
            int degree = i * (26-(ch-'a'));
            ans += degree;
        }
        return ans;
    }
};