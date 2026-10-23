class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        // base cases


        int ans = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == i) continue;

            ans &= nums[i];
        }
        return max(ans, 0);
    }
};