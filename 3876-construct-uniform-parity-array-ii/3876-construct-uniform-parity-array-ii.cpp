class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        // base cases
        int n = nums.size();


        
        int odd_min = INT_MAX, even_min = INT_MAX;
        bool even = false, odd = false;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                even_min = min(even_min, nums[i]);
                even = true;
            }
            else{
                odd_min = min(odd_min, nums[i]);
                odd = true;
            }
        }
        if(odd == false || even == false) return true;
        
        if(even_min < odd_min) return false;
        return true;
    }
};