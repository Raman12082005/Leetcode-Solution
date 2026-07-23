class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        queue<pair<int, int>> q;
        int ones = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) ones++;
                else{
                    visited[i][j] = true;
                }
            }
        }
        // base case
        if(ones == 0) return 0;

        for(int i=0; i<m; i++){
            if(grid[i][0] == 1 && !visited[i][0]){
                ones--;
                q.push({i, 0});
                visited[i][0] = true;
            }
            if(grid[i][n-1] == 1 && !visited[i][n-1]){
                ones--;
                q.push({i, n-1});
                visited[i][n-1] = true;
            }
        }
        for(int j=0; j<n; j++){
            if(grid[0][j] == 1 && !visited[0][j]){
                ones--;
                q.push({0, j});
                visited[0][j] = true;
            }
            if(grid[m-1][j] == 1 && !visited[m-1][j]){
                ones--;
                q.push({m-1, j});
                visited[m-1][j] = true;
            }
        }
        // base case
        if(q.empty()) return ones;
        if(ones == 0) return 0;
        
        vector<int> nx = {1, -1, 0, 0}, ny = {0, 0, 1, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(int i=0; i<4; i++){
                int dx = r + nx[i];
                int dy = c + ny[i];
                if(dx>=0 && dx<m && dy>=0 && dy<n && !visited[dx][dy] && grid[dx][dy] == 1){
                    ones--;
                    if(ones == 0) return 0;
                    visited[dx][dy] = true;
                    q.push({dx, dy});
                }
            }
        }
        return ones;
    }
};