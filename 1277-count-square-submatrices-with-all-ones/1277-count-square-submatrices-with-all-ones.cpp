class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // base cases

        int cnt = 0;
        vector<int> prev(m, 0), curr(m, 0);
        for(int j=0; j<m; j++){
            curr[j] = matrix[0][j];
            cnt += curr[j];
        }
        prev = curr;

        for(int i=1; i<n; i++){
            curr[0] = matrix[i][0];
            cnt += curr[0];
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 1){
                    curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
                    cnt += curr[j];
                }
                else curr[j] = 0;
            }
            prev = curr;
        }
        return cnt;
    }
};