class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        // base cases



        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        int first = n-1, sec = m-1;
        double ans = 0;
        while(first >= 0 && sec >= 0){
            ans += (double)(prices[first] * (100 - discounts[sec])) / 100;
            first--;
            sec--;
        }
        while(first >= 0){
            ans += prices[first];
            first--;
        }
        return ans;
    }
};