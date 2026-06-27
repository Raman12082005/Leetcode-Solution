class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitsum = 0;
        int temp = n;
        while(temp > 0){
            digitsum += (temp%10);
            temp /= 10;
        }
        int squaresum = 0;
        temp = n;
        bool ans = false;
        while(temp > 0){
            squaresum += pow(temp%10, 2);
            temp /= 10;
            if(squaresum >= digitsum + 50){
                ans = true;
                break;
            }
        }
        return ans;
    }
};