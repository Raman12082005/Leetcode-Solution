class Solution {
public:
    string removeOuterParentheses(string str) {
        int n= str.size();
        if(n==0) return "";
        stack<char> st;
        string ans = "";
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(str[i]);
                continue;
            }
            if(str[i] == '('){
                st.push(str[i]);
            }
            if(str[i] == ')'){
                st.pop();
            }
            if(!st.empty()){
                ans+=str[i];
            }
        }
        return ans;
    }
};