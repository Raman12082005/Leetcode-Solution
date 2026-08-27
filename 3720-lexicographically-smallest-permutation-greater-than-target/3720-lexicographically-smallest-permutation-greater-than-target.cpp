class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of every character available in s.
        vector<int> total(26, 0);
        for (char c : s) {
            total[c - 'a']++;
        }

        // Characters currently used by the matching prefix of target.
        vector<int> used(26, 0);

        int i = 0;

        // Keep the prefix equal to target for as long as possible.
        while (i < n) {
            int c = target[i] - 'a';

            if (used[c] == total[c]) {
                break;
            }

            used[c]++;
            i++;
        }

        // Try to make the string larger, changing the latest possible
        // position first to preserve the longest equal prefix.
        while (i >= 0) {
            if (i < n) {
                int current = target[i] - 'a';

                // Choose the smallest available character greater than
                // target[i].
                for (int next = current + 1; next < 26; next++) {
                    if (used[next] == total[next]) {
                        continue;
                    }

                    string answer = target.substr(0, i);
                    answer += char('a' + next);

                    // Complete the suffix with the smallest ordering.
                    for (int c = 0; c < 26; c++) {
                        int remaining = total[c] - used[c];

                        if (c == next) {
                            remaining--;
                        }

                        answer += string(remaining, char('a' + c));
                    }

                    return answer;
                }
            }

            // The current position cannot be increased. Remove the
            // previous target character before moving one position left.
            if (i > 0) {
                used[target[i - 1] - 'a']--;
            }

            i--;
        }

        return "";
    }
};