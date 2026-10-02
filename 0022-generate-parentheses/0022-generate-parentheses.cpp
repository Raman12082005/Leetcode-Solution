class Solution {
public:
    void helper(vector<string>& ans, int open, int close, string str){
        // base cases
        if(close == 0){
            ans.push_back(str);
        }

        if(open != 0){
            helper(ans, open-1, close, str + "(");
        }
        if(close > open){
            helper(ans, open, close-1, str + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, n, "");
        return ans;
    }
};