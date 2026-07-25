class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        int maxidx = -1, firstval = -1;
        for(int i=0; i<str.size(); i++){
            if(str[i]-'0' > firstval){
                firstval = str[i]-'0';
                maxidx = i;
            }
        }
        int secval = -1;
        for(int i=0; i<str.size(); i++){
            if(i != maxidx){
                if(str[i]-'0' > secval){
                    secval = str[i]-'0';
                }
            }
        }
        return firstval * secval;
    }
};