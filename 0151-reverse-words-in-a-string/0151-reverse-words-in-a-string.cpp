class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(), s.end());

        for(int i=0; i<s.size(); i++){
                string word = "";
            while(s.size()>i && s[i] != ' '){
                word += s[i++];
            }
            reverse(word.begin(), word.end());

            if(word.size() > 0){
                ans += ' ' + word;
            }
        }
        return ans.substr(1, ans.size()-1);
    }
};