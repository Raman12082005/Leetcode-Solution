class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        // base cases


        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res[i][(j-rowShift[i]+n)%n] = grid[i][j];
            }
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                grid[(i-colShift[j]+n)%n][j] = res[i][j];
            }
        }
        return grid;
    }
};