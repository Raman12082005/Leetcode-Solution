class Solution {
public:
    vector<string> createGrid(int n, int m) {
        // base cases



        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for(int i=0; i<n; i++) grid[i][m-1] = '.';
        for(int j=0; j<m-1; j++) grid[0][j] = '.';

        vector<string> res;
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=0; j<m; j++){
                str += grid[i][j];
            }
            res.push_back(str);
        }
        return res;
    }
};