class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // base cases



        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'S';
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                board[i][n-1] = 'S';
            }
        }
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = 'S';
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1, j});
                board[m-1][j] = 'S';
            }
        }
        vector<int> nx = {1, -1, 0, 0}, ny = {0, 0, 1, -1};
        while(!q.empty()){
            pair<int, int> it = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int dx = it.first + nx[i];
                int dy = it.second + ny[i];
                
                if(dx>=0 && dx<m && dy>=0 && dy<n && board[dx][dy] == 'O'){
                    board[dx][dy] = 'S';
                    q.push({dx, dy});
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};