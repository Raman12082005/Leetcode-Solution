class Solution {
public:
    const int MOD = 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // base cases


        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
        dp[0][0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int right = dp[i][j][0];
                int down = dp[i][j][1];
                
                if(grid[i][j] == 0){
                    int ways = (right + down) % MOD;

                    if(i+1 < m) dp[i+1][j][1] = (dp[i+1][j][1] + ways) % MOD;
                    if(j+1 < n) dp[i][j+1][0] = (dp[i][j+1][0] + ways) % MOD;
                }
                else{
                    if(j+1 < n) dp[i][j+1][0] = (dp[i][j+1][0] + down) % MOD;
                    if(i+1 < m) dp[i+1][j][1] = (dp[i+1][j][1] + right) % MOD;
                }
            }
        }
        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    }
};