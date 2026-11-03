class Solution {
public:
    bool isvalid(int x, unordered_map<int, int>& mpp){
        for(auto it : mpp){
            int a = it.first;
            int freq = it.second;

            // case 1 -> a + b = x
            int b = x - a;
            if(b > 0 && mpp.count(b)){
                if(a != b || (a == b && freq >= 2)) return false;
            }

            // case 2 -> a + x = b
            b = a + x;
            if(mpp.count(b)) return false;
        }
        return  true;
    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n <= 2) return n;

        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> mpp;
        while(j < n){
            if(isvalid(nums[j], mpp)){
                mpp[nums[j]]++;
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};