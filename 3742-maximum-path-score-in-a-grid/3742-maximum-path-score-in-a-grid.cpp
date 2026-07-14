class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // base cases


        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        int a = ((grid[0][0] == 0) ? 0 : 1);
        dp[0][0][a] = grid[0][0];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int cost = a; cost<=k; cost++){
                    if(dp[i][j][cost] == -1) continue;

                    // downward movement
                    if(i+1 < m){
                        int ncost = cost + ((grid[i+1][j] == 0) ? 0 : 1);

                        if(ncost <= k){
                            dp[i+1][j][ncost] = max(dp[i+1][j][ncost], dp[i][j][cost] + grid[i+1][j]);
                        }
                    }
                    // rightwrad movement
                    if(j+1 < n){
                        int ncost = cost + ((grid[i][j+1] == 0) ? 0 : 1);

                        if(ncost <= k){
                            dp[i][j+1][ncost] = max(dp[i][j+1][ncost], dp[i][j][cost] + grid[i][j+1]);
                        }
                    }
                }
            }
        }
        int ans = -1;
        for(int cost = a; cost<=k; cost++){
            ans = max(ans, dp[m-1][n-1][cost]);
        }
        return ans;
    }
};