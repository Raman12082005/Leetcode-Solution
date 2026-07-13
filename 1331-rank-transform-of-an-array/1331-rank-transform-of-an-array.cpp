class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mpp;
        int rank = 1;
        for(auto it : temp){
            if(!mpp.count(it)){
                mpp[it] = rank;
                rank++;
            }
        }

        vector<int> ans;
        for(auto it : arr){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};