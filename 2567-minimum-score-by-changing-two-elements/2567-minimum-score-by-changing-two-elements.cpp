class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n == 3) return 0;

        sort(nums.begin(), nums.end());
        int ans = abs(nums[n-1] - nums[2]);
        ans = abs(min(ans, nums[n-2] - nums[1]));
        ans = abs(min(ans, nums[n-3] - nums[0]));
        return ans;
    }
};