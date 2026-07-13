class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1; i<=9; i++){
            string s = to_string(i);
            for(int j=i+1; j<=9; j++){
                s += to_string(j);
                int val = stoi(s);
                if(val > high) break;
                if(val >= low && val<=high) ans.push_back(val);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};