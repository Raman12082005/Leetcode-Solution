class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        // base cases

        

        int maxi = *max_element(arr2.begin(), arr2.end());
        int count = 0;
        for(auto x : arr1){
            bool valid = true;

            for(auto y : arr2){
                if(abs(x-y) <= d){
                    valid = false;
                    break;
                }
            }
            if(valid) count++;
        }
        return count;
    }
};