class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        // base cases


        int ans = 0;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int i=1; i<n; i++){
                if(s[i] == s[i-1]) cnt++;
            }

            if(cnt == k) ans++;

            char ch = s[n-1];
            s.pop_back();
            s = ch + s;
        }
        return ans;
    }
};