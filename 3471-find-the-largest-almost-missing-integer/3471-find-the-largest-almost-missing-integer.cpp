class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        // base cases
        if(n == k) return *max_element(nums.begin(), nums.end());
        if(k == 1){
            unordered_map<int, int> mpp;
            for(auto it : nums) mpp[it]++;

            int ans = -1;
            for(auto it : mpp){
                if(it.second == 1) ans = max(ans, it.first);
            }
            return ans;
        }

        int first = nums[0], firstcount = 0;
        int last = nums[n-1], lastcount = 0;
        for(auto it : nums){
            if(it == first) firstcount++;
            if(it == last) lastcount++;
        }
        
        int ans = -1;
        if(firstcount == 1) ans = max(ans, first);
        if(lastcount == 1) ans = max(ans, last);
        return ans;
    }
};