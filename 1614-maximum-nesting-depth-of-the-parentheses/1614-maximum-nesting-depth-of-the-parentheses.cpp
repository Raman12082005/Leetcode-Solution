class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, n= s.size();
        int ans = 0;
        for(auto ch : s){
            if(ch == '(') depth++;
            ans = max(depth, ans);
            if(ch == ')') depth--;
        }
        return ans;
    }
};