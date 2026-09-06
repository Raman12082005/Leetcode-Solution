class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        // base cases


        int ans = 0;
        long long prevsum = 0, nextsum = 0;
        for(int i=0; i<n/2; i++) prevsum += nums[i];
        for(int i=n/2; i<n; i++) nextsum += nums[i];
        long long diff = prevsum - nextsum;
        if(diff > 0) ans++;

        int first = (n-1)/2, sec = n-1;
        for(int i=0; i<n-1; i++){
            diff += 2LL * nums[sec];
            diff -= 2LL * nums[first];

            sec--;
            first--;
                
            if(first == -1){
                first = n-1;
            }

            if(diff > 0) ans++;
        }
        return ans;
    }
};