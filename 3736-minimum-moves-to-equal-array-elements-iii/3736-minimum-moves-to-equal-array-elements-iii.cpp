class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n == 1) return 0;

        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(auto it : nums) ans += (maxi - it);
        return ans;
    }
};