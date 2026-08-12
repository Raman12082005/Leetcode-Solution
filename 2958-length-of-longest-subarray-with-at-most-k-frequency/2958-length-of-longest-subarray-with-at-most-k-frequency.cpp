class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        // base cases


        int ans = -1;
        int back = 0, front = 0;
        unordered_map<int, int> mpp;
        while(front < n){
            mpp[nums[front]]++;

            while(back<front && back<n && mpp[nums[front]]>k){
                mpp[nums[back]]--;
                back++;
            }
            ans = max(ans, front-back+1);
            front++;
        }
        return ans;
    }
};