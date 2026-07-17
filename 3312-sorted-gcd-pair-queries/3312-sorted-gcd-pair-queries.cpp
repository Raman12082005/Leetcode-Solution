class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> freq(mx+1, 0);

        for(int x : nums) freq[x]++;

        vector<long long> cnt(mx+1, 0);
        for(int d = 1; d<=mx; d++){
            for(int multiple = d; multiple<=mx; multiple += d){
                cnt[d] += freq[multiple];
            }
        }
        vector<long long> pairs(mx+1, 0);
        for(int d = mx; d>=1; d--){
            pairs[d] = cnt[d] * (cnt[d]-1)/2;
            for(int multiple=2*d; multiple<=mx; multiple+=d){
                pairs[d] -= pairs[multiple];
            }
        }
        vector<long long> prefix(mx+1, 0);
        for(int d=1; d<=mx; d++){
            prefix[d] = prefix[d-1] + pairs[d];
        }

        int m = queries.size();
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            ans[i] = lower_bound(prefix.begin(), prefix.end(), queries[i]+1) - prefix.begin();
        }
        return ans;
    }
};