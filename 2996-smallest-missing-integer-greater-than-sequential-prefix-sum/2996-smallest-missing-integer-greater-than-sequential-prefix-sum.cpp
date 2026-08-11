class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int target = nums[0];
        while(i<n && nums[i] == nums[i-1]+1){
            target += nums[i];
            i++;
        }

        while(find(nums.begin(), nums.end(), target) != nums.end()) target++;
        return target;
    }
};