class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // base case
        if(k == 0) return grid;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> process;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                process.push_back(grid[i][j]);
            }
        }
        for(int i=0; i<k; i++){
            process.insert(process.begin()+0, process.back());
            process.pop_back();
        }
        int idx = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = process[idx];
                idx++;
            }
        }
        return grid;
    }
};