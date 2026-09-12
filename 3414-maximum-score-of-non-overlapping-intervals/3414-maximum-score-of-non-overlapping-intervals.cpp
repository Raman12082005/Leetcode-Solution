class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    // Returns true if a is lexicographically smaller than b
    bool smaller(vector<int>& a, vector<int>& b) {
        return lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: [left, right, weight, original_index]
        vector<array<long long, 4>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        // right endpoints
        vector<long long> rights(n);

        for (int i = 0; i < n; i++) {
            rights[i] = v[i][1];
        }

        // dp[k][i] =
        // best answer using at most k intervals
        // from the first i intervals
        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int k = 1; k <= 4; k++) {

            for (int i = 1; i <= n; i++) {

                // Option 1: Don't take interval i-1
                dp[k][i] = dp[k][i - 1];

                // Current interval
                int current = i - 1;

                long long left = v[current][0];
                long long weight = v[current][2];
                int originalIndex = v[current][3];

                // Find number of intervals whose right < current left
                int j = lower_bound(
                    rights.begin(),
                    rights.end(),
                    left
                ) - rights.begin();

                // Option 2: Take current interval
                State candidate = dp[k - 1][j];

                candidate.score += weight;
                candidate.indices.push_back(originalIndex);

                // Indices must be sorted because answer
                // must be lexicographically smallest.
                sort(
                    candidate.indices.begin(),
                    candidate.indices.end()
                );

                // Choose better score
                if (candidate.score > dp[k][i].score) {
                    dp[k][i] = candidate;
                }
                // Same score -> lexicographically smaller
                else if (candidate.score == dp[k][i].score &&
                         smaller(candidate.indices, dp[k][i].indices)) {
                    dp[k][i] = candidate;
                }
            }
        }

        return dp[4][n].indices;
    }
};