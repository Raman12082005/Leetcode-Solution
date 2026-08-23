class Solution {
public:
    bool isPalindromic(string s) {
        string res = "";
        for(char ch : s){
            char c = (int)ch;

            for(int i=7; i>=0; i--){
                res += ((c>>i)&1) + '0';
            }
        }
        int left = 0, right = res.size()-1;
        while(left < right){
            if(res[left] != res[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};