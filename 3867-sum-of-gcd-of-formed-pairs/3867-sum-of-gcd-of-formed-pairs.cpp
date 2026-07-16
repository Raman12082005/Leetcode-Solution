class Solution {
public:
    long long gcd(long long a, long long b){
        if(a > b) swap(a, b);
        while(a != 0){
            long long rem = b % a;
            b = a;
            a = rem;
        }
        return b;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n == 1) return 0;

        vector<long long> gcdprefix(n);
        gcdprefix[0] = nums[0];
        long long mx = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] >= mx){
                mx = nums[i];
                gcdprefix[i] = mx;
            }
            else{
                gcdprefix[i] = gcd(nums[i], mx);
            }
        }

        sort(gcdprefix.begin(), gcdprefix.end());
        long long gcdsum = 0;
        for(int i=0; i<n/2; i++){
            gcdsum += gcd(gcdprefix[i], gcdprefix[n-i-1]);
        }
        return gcdsum;
    }
};