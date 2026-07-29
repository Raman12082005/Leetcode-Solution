class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        // base cases


        vector<int> freq(26, 0);
        for(char ch : s) freq[ch-'a']++;
        char ch = '.';
        string res = "";
        for(int i=0; i<26; i++){
            int x = freq[i];
            if(x == 0) continue;
            if(x%2 == 1) ch = i+'a';
            res.append(x/2, i+'a');
        }
        if(ch != '.') res += ch;
        int i = (ch == '.') ? res.size()-1 : res.size()-2;
        while(i >= 0){
            res += res[i];
            i--;
        }
        return res;
    }
};