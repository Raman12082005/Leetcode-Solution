class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n == 2) return 1;

        int ans = 0;
        map<pair<int, int>, int> mpp;
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]) ans++;
            else{
                int first = min(nums[i], nums[i+1]);
                int sec = max(nums[i], nums[i+1]);
                mpp[make_pair(first, sec)]++;
            }
        }
        int mx = 0;
        for(auto it : mpp){
            mx = max(mx, it.second);
        }
        return ans += mx;
    }
};