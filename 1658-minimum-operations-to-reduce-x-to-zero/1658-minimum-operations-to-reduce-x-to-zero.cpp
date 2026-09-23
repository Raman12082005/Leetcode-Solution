class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        // base cases


        long long totalsum = 1LL * accumulate(nums.begin(), nums.end(), 0);
        long long reqsum = totalsum - x;
        // base case
        if(reqsum < 0) return -1;
        if(reqsum == 0){
            return n;
        }


        int length = -1;
        long long sum = 0;
        int left = 0;
        
        for(int i=0; i<n; i++){
            sum += nums[i];

            while(left <= i && sum > reqsum){
                sum -= nums[left];
                left++;
            }
            
            if(sum == reqsum){
                length = max(length, i-left+1);
            }
        }
        if(length == -1) return -1;
        return n-length;
    }
};