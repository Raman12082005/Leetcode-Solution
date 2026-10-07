class Solution {
public:
    vector<string> ans;
    void helper(int n, string s, int opening, int closing){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }

        if(opening < n){
            helper(n, s+'(', opening+1, closing);
        }
        if(closing < opening && closing < n){
            helper(n, s+')', opening, closing+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s = "";
        int opening = 0, closing = 0;
        helper(n, s, opening, closing);
        return ans;
    }
};