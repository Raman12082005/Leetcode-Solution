class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0, closing = 0;
        int count = 0;
        for(auto it : s){
            if(it == '(') opening++;
            else{
                if(opening != 0) opening--;
                else count++;
            }
        }
        return count += opening;
    }
};