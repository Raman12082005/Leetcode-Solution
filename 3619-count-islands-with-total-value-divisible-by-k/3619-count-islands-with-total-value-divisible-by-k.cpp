class Solution {
public:
    int n, m;
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    void helper(int i, int j, long long& count, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        visited[i][j] = true;
        count += grid[i][j];

        for(int k=0; k<4; k++){
            int row = i + dx[k];
            int col = j + dy[k];
            if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || visited[row][col] == true){
                continue;
            }
            helper(row, col, count, visited, grid);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        // base cases



        int island = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0 && visited[i][j] == false){
                    long long count = 0;
                    helper(i, j, count, visited, grid);
                    if(count%k == 0) island++;
                }
            }
        }
        return island;
    }
};