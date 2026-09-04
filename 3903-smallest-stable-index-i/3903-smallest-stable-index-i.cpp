class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // base cases

        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] > prefix[i-1]) prefix[i] = nums[i];
            else prefix[i] = prefix[i-1];
        }

        suffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i] < suffix[i+1]) suffix[i] = nums[i];
            else suffix[i] = suffix[i+1];
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int val = prefix[i] - suffix[i];
            if(val <= k && val < ans){
                return i;
            }
        }
        return -1;
    }
};