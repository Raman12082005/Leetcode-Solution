class Solution {
public:
    const int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        // base cases



        long long ans = 0;
        long long prefix = 0;
        long long even = 1, odd = 0;
        for(auto x : arr){
            prefix += x;
            if(prefix%2 == 0){
                ans = (ans + odd) % MOD;
                even++;
            }
            else{
                ans = (ans + even) % MOD;
                odd++;
            }
        }
        return ans;
    }
};