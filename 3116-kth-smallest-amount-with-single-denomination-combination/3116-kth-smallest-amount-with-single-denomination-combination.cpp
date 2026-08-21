class Solution {
public:

    bool possible(long long x, vector<int>& coins, int k) {
        int n = coins.size();
        long long count = 0;

        // All non-empty subsets of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long lcm = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    long long g = gcd(lcm, (long long)coins[i]);

                    // Avoid overflow
                    if (lcm > x / (coins[i] / g)) {
                        overflow = true;
                        break;
                    }

                    lcm = lcm / g * coins[i];
                }
            }

            if (overflow || lcm > x)
                continue;

            long long multiples = x / lcm;

            // Odd number of elements -> add
            if (bits % 2 == 1)
                count += multiples;
            // Even number -> subtract
            else
                count -= multiples;
        }

        return count >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1e11;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (possible(mid, coins, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};