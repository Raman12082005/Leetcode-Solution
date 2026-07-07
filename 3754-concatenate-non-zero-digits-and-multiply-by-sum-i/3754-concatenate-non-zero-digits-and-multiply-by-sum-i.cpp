class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, x = 0;
        while(n){
            int lastdigit = n%10;
            n /= 10;
            sum += lastdigit;
            if(lastdigit != 0){
                x += lastdigit;
                x *= 10;
            }
        }
        x /= 10;
        long long y = 0;
        while(x){
            int temp = x % 10;
            x /= 10;
            y += temp;
            y *= 10;
        }
        y /= 10;
        return sum * y;
    }
};