class Solution {
public:
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    void helper(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        visited[r][c] = true;

        for(int k=0; k<4; k++){
            int rx = r + dx[k];
            int cx = c + dy[k];

            if(rx<0 || rx>=n || cx<0 || cx>=m || grid[rx][cx] == '0' || visited[rx][cx] == true){
                continue;
            } 
            helper(rx, cx, grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // base cases


        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    islands++;
                    helper(i, j, grid, visited);
                }
            }
        }
        return islands;
    }
};