class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        // base cases


        int count = 0;
        int open = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else if(i < n-1 && s[i] == ')' && s[i+1] == ')'){
                i++;
                if(open == 0) count++;
                else open--;
            }
            else{
                if(open == 0) count += 2;
                else{
                    count++;
                    open--;
                }
            }
        }
        count += 2*open;
        return count;
    }
};