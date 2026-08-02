class Solution {
public:
    long long gcd(long long a, long long b){
        if(a > b) swap(a, b);
        while(a){
            long long rem = b%a;
            b = a;
            a = rem;
        }
        return b;
    }
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long g = gcd(nums[i], nums[j]);
                ans = max(ans, (1ll*nums[i]*nums[j])/(g*g));
            }
        }
        return ans;
    }
};