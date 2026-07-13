class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int base = grid[0][0];
        for(auto it : grid){
            for(auto val : it){
                if(val%x != base%x) return -1;
                arr.push_back(val);
            }
        }
        sort(arr.begin(), arr.end());
        int target = arr[arr.size()/2];
        int operations = 0;
        for(auto val : arr){
            operations += abs(target - val) / x;
        }
        return operations;
    }
};