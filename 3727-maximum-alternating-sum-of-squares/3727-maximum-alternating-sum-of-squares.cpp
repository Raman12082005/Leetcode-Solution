class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // base cases



        for(int i=0; i<n; i++){
            if(nums[i] < 0) nums[i] *= -1;
        }
        sort(nums.begin(), nums.end());
        long long res = 0;
        int idx = n-1;
        for(int i=0; i<(n+1)/2 && idx >= 0; i++){
            res += (nums[idx] * nums[idx]);
            idx--;
        }
        while(idx >= 0){
            res -= (nums[idx] * nums[idx]);
            idx--;
        }
        return res;
    }
};