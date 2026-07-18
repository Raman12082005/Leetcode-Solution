class Solution {
public:
    int gcd(int a, int b){
        while(a != 0){
            int rem = b%a;
            b = a;
            a = rem;
        }
        return b;
    }
    int findGCD(vector<int>& nums) {
        int smallestnum = *min_element(nums.begin(), nums.end());
        int largestnum = *max_element(nums.begin(), nums.end());
        return gcd(smallestnum, largestnum);
    }
};