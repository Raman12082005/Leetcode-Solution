class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        const int MOD = 1e9+7;
        // base cases
        if(board[0][0] == 'X' || board[n-1][m-1] == 'X') return {0, 0};

        vector<vector<int>> score(n, vector<int>(m, -1));
        score[n-1][m-1] = 0;
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        cnt[n-1][m-1] = 1;

        for(int j=m-2; j>=0; j--){
            if(board[n-1][j] == 'X') break;
            if(score[n-1][j+1] == -1) break;
            int val = (board[n-1][j] == 'E' || board[n-1][j] == 'S') ? 0 : board[n-1][j] - '0';
            score[n-1][j] = score[n-1][j+1] + val;
            cnt[n-1][j] = cnt[n-1][j+1];
        }
        for(int i=n-2; i>=0; i--){
            if(board[i][m-1] == 'X') break;
            if(score[i+1][m-1] == -1) break;
            int val = (board[i][m-1] == 'E' || board[i][m-1] == 'S') ? 0 : board[i][m-1] - '0';
            score[i][m-1] = score[i+1][m-1] + val;
            cnt[i][m-1] = cnt[i+1][m-1];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                if(board[i][j] == 'X') continue;
                if(i == 0 && j == 0) continue;

                int val = (board[i][j] == 'E' || board[i][j] == 'S') ? 0 : board[i][j] - '0';
                int best = -1;
                int ways = 0;
                auto helper = [&](int ni, int nj){
                    if(score[ni][nj] == -1) return;
                    if(score[ni][nj] > best){
                        best = score[ni][nj];
                        ways = cnt[ni][nj];
                    }
                    else if(score[ni][nj] == best){
                        ways = (ways + cnt[ni][nj]) % MOD;
                    }
                };

                helper(i+1, j);
                helper(i, j+1);
                helper(i+1, j+1);

                if(best == -1) continue;
                score[i][j] = best + val;
                cnt[i][j] = ways;
            }
        }

        int best = -1;
        int ways = 0;
        auto helper = [&](int ni, int nj){
            if(score[ni][nj] == -1) return;
            if(score[ni][nj] > best){
                best = score[ni][nj];
                ways = cnt[ni][nj];
            }
            else if(score[ni][nj] == best){
                ways = (ways + cnt[ni][nj]) % MOD;
            }
        };

        helper(1, 0);
        helper(0, 1);
        helper(1, 1);

        if(best == -1) return {0, 0};
        return {best % MOD, ways % MOD};
    }
};