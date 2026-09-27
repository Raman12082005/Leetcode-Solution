class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        // base cases


        
        while(true){
            int f = -1, l = -1;
            for(int i=0; i<n; i++){
                if(s[i] == '('){
                    f = i;
                }
            }
            if(f == -1) break;

            for(int i=f+1; i<n; i++){
                if(s[i] == ')'){
                    l = i;
                    break;
                }
            }

            reverse(s.begin()+f+1, s.begin()+l);
            s.erase(l , 1);
            s.erase(f, 1);
        }
        return s;
    }
};