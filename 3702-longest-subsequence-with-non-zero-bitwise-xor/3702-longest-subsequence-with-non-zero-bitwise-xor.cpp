class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        // base cases


        int ans = 0;
        for(auto it : nums) ans ^= it;
        if(ans != 0) return n;
        for(auto it : nums){
            int temp = ans ^ it;
            if(temp != 0) return n-1;
        }
        return 0;
    }
};