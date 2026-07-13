class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string, vector<string>> ans;
        for(auto s : str){
            string key = s;
            sort(key.begin(), key.end());
            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto it : ans){
            result.push_back(it.second);
        }
        return result;
    }
};