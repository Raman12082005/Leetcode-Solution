class Solution {
public:
    int helper(int i, int M, vector<int>& suffix, vector<vector<int>>& dp, int n){
        /// base cases
        if(i>=n) return 0;
        if(i+2*M >= n) return suffix[i];

        if(dp[i][M] != -1) return dp[i][M];
        int ans = 0;
        for(int X = 1; X<=2*M && X+i<=n; X++){
            int opponent = helper(i+X, max(X, M), suffix, dp, n);
            ans = max(ans, suffix[i]-opponent);
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // base cases


        vector<int> suffix(n+1, 0);
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        for(int i=n-1; i>=0; i--) suffix[i] = suffix[i+1] + piles[i];
        return helper(0, 1, suffix, dp, n);
    }
};