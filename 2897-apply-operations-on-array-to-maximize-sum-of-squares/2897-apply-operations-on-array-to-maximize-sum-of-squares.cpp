class Solution {
public:
    const int MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        // base cases



        vector<int> cnt(31, 0);
        for(auto num : nums){
            for(int i=0; i<31; i++){
                if(1 & (num >> i)){
                    cnt[i]++;
                }
            }
        }

        long long ans = 0;
        while(k--){
            long long x = 0;
            for(int i=0; i<31; i++){
                if(cnt[i] > 0){
                    x |= (1LL << i);
                    cnt[i]--;
                }
            }
            ans = (ans + (1LL * x*x) % MOD) % MOD;
        }
        return ans;
    }
};