class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // dp[i] = longest suffix of word2
        // that can be formed exactly from word1[i...]
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            dp[i] = dp[i + 1];

            if (dp[i + 1] < m &&
                word1[i] == word2[m - dp[i + 1] - 1]) {

                dp[i]++;
            }
        }

        vector<int> ans;

        int j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {

                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch
            else if (!changed &&
                     dp[i + 1] >= m - j - 1) {

                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};