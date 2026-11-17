class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        // base cases




        int inc = 1, dec = 1;
        
        int fir = 0, sec = 1;
        while(fir < sec && sec < n){
            if(nums[sec] > nums[sec-1]) inc = max(inc, sec-fir+1);
            else fir = sec;
            sec++;
        }

        fir = 0, sec = 1;
        while(fir < sec && sec < n){
            if(nums[sec] < nums[sec-1]) dec = max(dec, sec-fir+1);
            else fir = sec;
            sec++;
        }
        return max(inc, dec);
    }
};