class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n == 1) return 0;
        if(n == 2) return abs(nums[0] - nums[1]);

        sort(nums.begin(), nums.end());
        long long target = -1;
        if(n % 2 != 0) target = nums[n/2];
        else{
            int sec = n/2;
            int first = sec-1;

            if(nums[first] - nums[first-1] <= nums[sec+1] - nums[sec]) target = nums[first];
            else target = nums[sec];
        }

        long long res = 0;
        for(auto it : nums) res += abs(it - target);
        return res;
    }
};