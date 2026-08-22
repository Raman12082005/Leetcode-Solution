class Solution {
public:
    bool checkDivisibility(int n) {
        long long temp = n;
        long long pdt = 1;
        long long sum = 0;
        while(n){
            int t = n%10;
            n /= 10;
            pdt *= t;
            sum += t;
        }
        if(temp%(sum+pdt) == 0) return true;
        return false;
    }
};