class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        // base cases


        vector<int> res;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        for(int i=low+1; i<high; i++){
            auto it = find(nums.begin(), nums.end(), i);
            if(it == nums.end()) res.push_back(i);
        }
        return res;
    }
};