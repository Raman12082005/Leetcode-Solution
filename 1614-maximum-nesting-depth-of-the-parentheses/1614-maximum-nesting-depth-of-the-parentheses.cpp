class Solution {
public:
    int maxDepth(string s) {
        int maxpranthesis = 0, openbracket = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') openbracket++;
            if(s[i] == ')') openbracket--;
            maxpranthesis = max(maxpranthesis, openbracket);
        }
        return maxpranthesis;
    }
};