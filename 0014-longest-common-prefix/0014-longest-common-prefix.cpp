class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(), str.end());

        string ans = "";
        string first = str[0];
        string last = str[str.size()-1];
        for(int i=0; i<min(first.size(), last.size()); i++){
            if(first[i] != last[i]) return ans;
            else ans += first[i];
        }
        return ans;
    }
};