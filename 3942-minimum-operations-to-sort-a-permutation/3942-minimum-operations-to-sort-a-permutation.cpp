class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if(n == 1) return 0;
        if(n == 2) return nums[0] < nums[1] ? 0 : 1;

        int zidx = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zidx = i;
                break;
            }
        }
        
        // moving right
        bool case1 = true;
        int val = 1;
        for(int i=0; i<n-1; i++){
            if(nums[(zidx + val) % n] == val){
                val++;
            }
            else{
                case1 = false;
                break;
            }
        }

        // moving left
        bool case2 = true;
        val = 1;
        for(int i=0; i<n-1; i++){
            if(nums[(zidx - val + n) % n] == val){
                val++;
            }
            else{
                case2 = false;
                break;
            }
        }
        
        int ans = INT_MAX;
        if(case1){
            ans = min(ans, zidx);
            ans = min(ans, n-zidx+2);
        }
        if(case2){
            ans = min(ans, zidx+2);
            ans = min(ans, n-zidx);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};