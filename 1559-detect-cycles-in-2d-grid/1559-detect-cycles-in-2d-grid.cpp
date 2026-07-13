class Solution {
public:
    vector<int> nx = {1, -1, 0, 0}, ny = {0, 0, 1, -1};
    bool dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<pair<int, int>>>& parent){
        visited[r][c] = true;
        int m = grid.size();
        int n = grid[0].size();
        // base cases
        

        for(int i=0; i<4; i++){
            int dx = r + nx[i];
            int dy = c + ny[i];

            if(dx>=0 && dx<m && dy>=0 && dy<n){
                if(grid[r][c] == grid[dx][dy]){
                    if(!visited[dx][dy]){
                        parent[dx][dy] = make_pair(r, c);
                        if(dfs(dx, dy, grid, visited, parent)) return true;
                    }
                    else{
                        if(parent[r][c] != make_pair(dx, dy)){
                            return true;
                        }
                        else continue;
                    }
                }
                else continue;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // base cases


        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, {-1, -1}));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    if(dfs(i, j, grid, visited, parent)) return true;
                }
            }
        }
        return false;
    }
};