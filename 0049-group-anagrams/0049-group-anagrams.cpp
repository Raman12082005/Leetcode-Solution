class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n = str.size();
        // base cases



        vector<vector<string>> ans;
        for(int i=0; i<str.size(); i++){
            string s = str[i];
            sort(s.begin(), s.end());
            vector<string> result;

            for(int j=i+1; j<str.size(); j++){
                string a = str[j];
                if(a.size() == s.size()){
                    sort(a.begin(), a.end());
                    if(a == s){
                        result.push_back(str[j]);
                        str.erase(str.begin()+j);
                        j--;
                    }
                }
            }
            result.push_back(str[i]);
            ans.push_back(result);
        }
        return ans;
    }
};