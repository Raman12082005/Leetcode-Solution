class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        // base cases


        int count = 0;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] == '(') st.push('(');
            else if(i < n-1 && s[i] == ')' && s[i+1] == ')'){
                i++;
                if(st.empty()) count++;
                else st.pop();
            }
            else{
                if(st.empty()) count += 2;
                else{
                    count++;
                    st.pop();
                }
            }
        }
        count += 2*st.size();
        return count;
    }
};