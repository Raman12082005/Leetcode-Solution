class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(auto it : nums){
            if(it >= max1){
                max3 = max2;
                max2 = max1;
                max1 = it;
            }
            else if(it >= max2){
                max3 = max2;
                max2 = it;
            }
            else if(it >= max3){
                max3 = it;
            }

            if(it <= min1){
                min2 = min1;
                min1 = it;
            }
            else if(it <= min2){
                min2 = it;
            }
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};