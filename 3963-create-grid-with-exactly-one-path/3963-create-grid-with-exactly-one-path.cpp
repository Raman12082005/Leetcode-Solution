class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string str1, str2;
        for(int j=0; j<n; j++){
            str1 += '.';
            str2 += '#';
        }
        str2[n-1] = '.';

        vector<string> ans(m);
        ans[0] = str1;
        for(int i=1; i<m; i++){
            ans[i] = str2;
        }
        return ans;
    }
};