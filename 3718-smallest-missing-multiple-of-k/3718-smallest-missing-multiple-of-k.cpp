class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        for(int i=1; i<201; i++){
            if(!s.count(k*i)) return i*k;
        }
        return -1;
    }
};