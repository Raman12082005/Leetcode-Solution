class Solution {
public:
    const int MOD = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long cost = 0;
        long long temp = k;
        long long a = 1;
        for(auto it : nums){
            if(it <= temp){
                temp -= it;
            }
            else{
                long long val = it - temp;
                long long div = (val + k -1) / k;
                long long b = a + div-1;

                __int128 sum = (__int128)(a+b)*div/2;
                cost = (cost + (long long)(sum%MOD))%MOD;
                
                a+=div;
                temp = (div*1LL*k) + temp;
                temp -= it;
            }
        }
        return (int)cost;
    }
};