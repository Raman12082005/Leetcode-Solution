class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<n-1;){
                int p=j+1, q=n-1;

                while(p<q){
                    long long sum=(long long)nums[i]+(long long)nums[p]+
                                  (long long)nums[q]+(long long)nums[j];
                    
                    if(sum<tar){
                        p++;
                    }
                    else if(sum>tar){
                        q--;
                    }
                    else{ //sum==tar
                        ans.push_back({nums[i], nums[p], nums[q], nums[j]});
                        p++;
                        q--;

                        while(p<q && nums[q]==nums[q+1]) q--;
                        //while(p<q && nums[p]==nums[p-1]) p++;
                    }
                }
                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
        }
        return ans;
    }
};