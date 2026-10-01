class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(int i=0;i<str.size();i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){//opening
                st.push(str[i]);
            }
            else{//closing
                if(st.size() == 0) return false;//empty stack case
                
                if((str[i] == ')' && st.top() == '(') ||
                    (str[i] == ']' && st.top() == '[') ||
                    (str[i] == '}' && st.top() == '{')){
                        st.pop();
                    }
                else{// no match found
                    return false;
                }
                
            }
        }
        return st.size() == 0;
    }
};