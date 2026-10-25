class Solution {
public:
    int n, m;
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    void helper(int i, int j, vector<vector<int>>& nums){
        nums[i][j] = -1;
        for(int k = 0; k<4; k++){
            int row = i + dx[k];
            int col = j + dy[k];

            if(row >= n || row < 0 || col >= m || col < 0) continue;
            if(nums[row][col] == 0) helper(row, col, nums);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        // base cases



        vector<vector<int>> nums = grid;
        for(int i=0; i<n; i++){
            if(nums[i][0] == 0) helper(i, 0, nums);
            if(nums[i][m-1] == 0) helper(i, m-1, nums);
        }
        for(int j = 0; j<m; j++){
            if(nums[0][j] == 0) helper(0, j, nums);
            if(nums[n-1][j] == 0) helper(n-1, j, nums);
        }

        int count = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(nums[i][j] == 0){
                    count++;
                    helper(i, j, nums);
                }
            }
        }
        return count;
    }
};