class Solution {
public:
    bool ispalindrome(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--; 
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        int startingidx = 0;
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if((j-i+1) > maxlen && ispalindrome(i, j, s)){
                    maxlen = j-i+1;
                    startingidx = i;
                }
            }
        }
        return s.substr(startingidx, maxlen);
    }
};