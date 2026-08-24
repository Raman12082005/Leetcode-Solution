class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> arr;
        // base cases
        if(n == 0) arr.push_back({lower, upper});

        sort(nums.begin(), nums.end());
        int prev = lower-1;
        for(auto it : nums){
            if(it > upper) break;
            if(it < lower) continue;

            if(it - prev > 1) arr.push_back({prev+1, it-1});
            prev = it;
        }
        if(upper - prev >= 1) arr.push_back({prev+1, upper});
        return arr;
    }
};