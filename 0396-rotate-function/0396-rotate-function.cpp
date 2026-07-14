class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        // base cases


        long long ans = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            ans += (nums[i] * i);
        }

        long long maxi = ans;
        for(int k=1; k<n; k++){
            ans += (sum - (nums[n-k]*n));
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};