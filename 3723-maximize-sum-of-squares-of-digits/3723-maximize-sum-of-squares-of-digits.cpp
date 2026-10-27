class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // base cases
        if(sum > 9*num) return "";

        string res = "";
        while(sum >= 9){
            res += '9';
            sum -= 9;
        }
        if(sum != 0){
            res += char('0' + sum);
            sum = 0;
        }
        if(res.size() == num) return res;
        else if(res.size() > num) return "";

        while(res.size() < num){
            res += '0';
        }
        return res;
    }
};