class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        // base cases


        string str = "";
        int first = 0;
        int opening = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') opening++;
            else opening--;

            if(opening == 0){
                str += s.substr(first+1, i-first-1);
                first = i+1;
            }
        }
        return str;
    }
};