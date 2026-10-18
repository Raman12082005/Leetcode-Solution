class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        // base cases


        stack<int> st;
        st.push(0);
        for(auto it : s){
            if(it == '(') st.push(0);
            else{
                int inner = st.top();
                st.pop();

                int score = (inner == 0) ? 1 : 2 * inner;
                st.top() += score;
            }
        }
        return st.top();
    }
};