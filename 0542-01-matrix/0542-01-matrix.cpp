class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        int ones = 0;
        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1) ones++;
                else{
                    q.push({i, j, 0});
                    result[i][j] = 0;
                }
            }
        }
        // base case
        if(ones == 0) return result;

        vector<int> nx = {1, -1, 0, 0}, ny = {0, 0, 1, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it[0];
            int c = it[1];
            int dist = it[2];
            for(int i=0; i<4; i++){
                int dx = r + nx[i];
                int dy = c + ny[i];
                if(dx>=0 && dx<m && dy>=0 && dy<n && result[dx][dy] == -1){
                    result[dx][dy] = dist+1;
                    ones--;
                    q.push({dx, dy, dist+1});
                    if(ones == 0) break;
                }
            }
        }
        return result;
    }
};