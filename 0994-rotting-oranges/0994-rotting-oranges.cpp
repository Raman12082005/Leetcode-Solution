class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0, rotten = 0;
        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2){
                    rotten++;
                    q.push({i, j, 0});
                }
            }
        }
        // base cases
        if(fresh == 0) return 0;
        if(rotten == 0) return -1;

        int ans = 0;
        vector<int> nx= {1, -1, 0, 0}, ny = {0, 0, 1, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it[0];
            int c = it[1];
            int time = it[2];
            ans = max(time, ans);
            for(int i=0; i<4; i++){
                int dx = r + nx[i];
                int dy = c + ny[i];
                if(dx>=0 && dx<m && dy>=0 && dy<n && grid[dx][dy] == 1){
                    fresh--;
                    grid[dx][dy] = 2;
                    q.push({dx, dy, time+1});
                }
            }
        }
        return (fresh == 0) ? ans : -1;
    }
};