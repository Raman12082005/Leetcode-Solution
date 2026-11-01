class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n == 1) return 0;

        int count = 0;
        int mini = *min_element(nums.begin(), nums.end());
        for(auto it : nums) count += (it - mini);
        return count;
    }
};