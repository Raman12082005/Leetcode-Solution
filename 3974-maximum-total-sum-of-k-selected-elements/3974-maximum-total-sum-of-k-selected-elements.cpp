class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        long long totalsum = 0;
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
           return a > b; 
        });
        for(int i=0; i<k; i++){
            if(mul > 1){
                totalsum += ((long long)nums[i] * mul);
                mul--;
            }
            else{
                totalsum += nums[i];
                mul--;
            }
        }
        return totalsum;
    }
};