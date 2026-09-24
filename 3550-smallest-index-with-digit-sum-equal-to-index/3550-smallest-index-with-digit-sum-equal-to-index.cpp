class Solution {
public:
    int sumOfDigits(int x){
        int sum = 0;
        while(x > 0){
            sum += (x%10);
            x/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        // base cases


        for(int i=0; i<n; i++){
            if(sumOfDigits(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};