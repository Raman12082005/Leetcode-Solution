class Solution {
public:
    bool isValid(string s) {
        // base cases
        if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;

        stack<char> st;
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if(ch == ')'){
                if(st.empty()) return false;
                if(st.top() != '(') return false;
                st.pop();
            }
            else if(ch == ']'){
                if(st.empty()) return false;
                if(st.top() != '[') return false;
                st.pop();
            }
            else if(ch == '}'){
                if(st.empty()) return false;
                if(st.top() != '{') return false;
                st.pop();
            }
        }
        return st.size() == 0;
    }
};