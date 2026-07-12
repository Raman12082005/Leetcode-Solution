class Solution {
public:
    bool helper(int r, int c, int m, int n, int k, vector<string>& grid, vector<vector<int>>& dp){
        if(r == m) return dp[m-1][n-1] == k;

        int nr = r;
        int nc = c+1;
        if(nc == n){
            nr = r + 1;
            nc = 0;
        }

        // option 1 : free cell
        grid[r][c] = '.';
        if(r==0 && c==0){
            dp[r][c] = 1;
        }
        else{
            dp[r][c] = (r>0 ? dp[r-1][c] : 0) + (c>0 ? dp[r][c-1] : 0);
        }
        if(dp[r][c] <= k){
            if(helper(nr, nc, m, n, k, grid, dp)) return true;
        }
        
        // option 2 : bolck cell
        if(!((c == 0 && r == 0) || (r == m-1 && c == n-1))){
            grid[r][c] = '#';
            dp[r][c] = 0;
            if(helper(nr, nc, m, n, k, grid, dp)) return true;
        }
        return false;
    }
    vector<string> createGrid(int m, int n, int k) {
        vector<string> grid(m, string(n, '.'));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(helper(0, 0, m, n, k, grid, dp)) return grid;
        return {};
    }
};