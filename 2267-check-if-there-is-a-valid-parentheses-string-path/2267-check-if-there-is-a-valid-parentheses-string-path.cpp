class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    bool helper(vector<vector<char>>& grid, int i, int j, int balance){
        if(grid[i][j] == '(') balance++;
        if(grid[i][j] == ')') balance--;
        // base cases
        if(balance < 0) return false;
        int remaining = (m-1-i) + (n-1-j);
        if(balance > remaining) return false;
        if(i == m-1 && j == n-1) return balance == 0;
        if(dp[i][j][balance] != -1) return dp[i][j][balance];

        bool ans = false;
        if(i+1<m) ans |= helper(grid, i+1, j, balance);
        if(j+1<n) ans |= helper(grid, i, j+1, balance);
        return dp[i][j][balance] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // base cases
        if(grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        if((m+n-1)%2 == 1) return false;

        dp.assign(m, vector<vector<int>>(n, vector<int>(m+n, -1)));
        return helper(grid, 0, 0, 0);
    }
};