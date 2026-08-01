class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        // base cases
        


        int zeroes = 0, ones = 0;
        int ans = 0;
        for(auto ch : s){
            if(ch == '0') zeroes++;
            else ones++;

            if(abs(ones - zeroes) <= 1) ans++;
        }
        return ans;
    }
};