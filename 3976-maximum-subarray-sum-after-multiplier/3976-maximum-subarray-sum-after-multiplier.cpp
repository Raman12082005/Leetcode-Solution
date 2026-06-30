class Solution {
public:
long long divide(int x, int k){
    if(x >= 0) return x/k;
    return -((-x)/k);
}
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long neg = -4e18;
        long long dp0 = neg;
        long long dp1 = neg;
        long long dp2 = neg;
        long long dp3 = neg;

        long long ans = LLONG_MIN;
        for(auto it : nums){
            long long multi = 1LL * it * k;
            long long div = divide(it, k);

            long long ndp0 = max({1LL * it, it + dp0});
            long long ndp1 = max({multi, dp0 + multi, dp1 + multi});
            long long ndp2 = max({div, dp0 + div, dp2 + div});
            long long ndp3 = max({dp1 + it, dp2 + it, dp3 + it});

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;
            dp3 = ndp3;

            ans = max({ans, dp0, dp1, dp2, dp3});
        }
        return ans;
    }
};