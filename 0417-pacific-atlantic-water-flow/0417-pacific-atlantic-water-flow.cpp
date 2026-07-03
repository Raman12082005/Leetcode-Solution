class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        visited[row][col] = true;

        int n = heights.size();
        int m = heights[0].size();

        for(int i=0; i<4; i++){
            int nx = row + dx[i];
            int ny = col + dy[i];

            // base cases
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(visited[nx][ny]) continue;

            if(heights[nx][ny] >= heights[row][col]) dfs(nx, ny, visited, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pv(n, vector<bool>(m, false));
        vector<vector<bool>> av(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            if(!pv[i][0]){
                dfs(i, 0, pv, heights);
            }
        }
        for(int j=0; j<m; j++){
            if(!pv[0][j]){
                dfs(0, j, pv, heights);
            }
        }

        for(int j=0; j<m; j++){
            if(!av[n-1][j]){
                dfs(n-1, j, av, heights);
            }
        }
        for(int i=0; i<n; i++){
            if(!av[i][m-1]){
                dfs(i, m-1, av, heights);
            }
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pv[i][j] && av[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};