class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;
        vector<int> odds(n+1, 0), evens(n+1, 0);
        int odd = 0, even = 0;
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 0) evens[i+1] = evens[i] + 1;
            else evens[i+1] = evens[i];
            
            if(nums[i]%2 == 1) odds[i+1] = odds[i] + 1;
            else odds[i+1] = odds[i];
        }
        
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                int o = odds[j] - odds[i-1];
                int e = evens[j] - evens[i-1];
                if(o == 0) continue;
                else if(1ll*e*b <= 1ll*a*o) ans++;
            }
        }
        return ans;
    }
};