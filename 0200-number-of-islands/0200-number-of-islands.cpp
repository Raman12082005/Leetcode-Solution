class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        // base cases
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c] == '0' || visited[r][c]) return;

        visited[r][c] = true;
        dfs(r+1, c, m, n, grid, visited);
        dfs(r, c+1, m, n, grid, visited);
        dfs(r-1, c, m, n, grid, visited);
        dfs(r, c-1, m, n, grid, visited);
    }    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // base cases


        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, m, n, grid, visited);
                }
            }
        }
        return cnt;
    }
};