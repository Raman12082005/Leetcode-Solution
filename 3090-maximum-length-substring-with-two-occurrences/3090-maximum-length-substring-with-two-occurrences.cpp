class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        // base cases



        unordered_map<char, int> mpp;
        int first = 0, sec = 0;
        int ans = 0;
        while(sec < n){
            mpp[s[sec]]++;

            if(mpp[s[first]] == 3) ans = max(ans, sec-first);
            while(mpp[s[sec]] == 3 && first < sec){
                mpp[s[first]]--;
                first++;
            }
            ans = max(ans, sec-first+1);
            sec++;
        }
        ans = max(ans, sec-first);
        return ans;
    }
};