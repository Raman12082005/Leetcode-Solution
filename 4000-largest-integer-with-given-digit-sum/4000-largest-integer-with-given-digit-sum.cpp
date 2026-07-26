class Solution {
public:
    int largestInteger(int n, int s) {
        // base cases


        vector<int> arr(n, 0);
        int i=0;
        while(s >= 9 && i < n){
            arr[i] = 9;
            s-=9;
            i++;
        }
        if(i == n && s!= 0) return -1;
        
        if(s != 0) arr[i] = s;

        int result = 0;
        for(auto it : arr){
            result *= 10;
            result += it;
        }
        return result;
        
    }
};