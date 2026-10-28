class Solution {
public:
    int helper(int i, int j, int xroi, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        // base cases
        if(i >= grid.size() || j >= grid[0].size()) return INT_MAX;

        xroi ^= grid[i][j];
        if(i == grid.size()-1 && j == grid[0].size()-1) return xroi;

        if(dp[i][j][xroi] != -1) return dp[i][j][xroi];
        
        int right = helper(i, j+1, xroi, dp, grid);
        int down = helper(i+1, j, xroi, dp, grid);

        return dp[i][j][xroi] = min(right, down);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1023+1, -1)));
        return helper(0, 0, 0, dp, grid);
    }
};