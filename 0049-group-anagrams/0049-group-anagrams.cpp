class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string, vector<string>> ans;
        for(auto s : str){
            vector<int> freq(26, 0);
            for(auto ch : s){
                freq[ch-'a']++;
            }

            string key = "";
            for(int num : freq){
                key += to_string(num)+"#";
            }
            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto it : ans){
            result.push_back(it.second);
        }
        return result;
    }
};