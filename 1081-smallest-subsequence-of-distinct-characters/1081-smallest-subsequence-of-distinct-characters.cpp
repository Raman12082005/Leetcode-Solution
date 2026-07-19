class Solution {
public:
    string smallestSubsequence(string s){
        int n = s.size();
        // base case


        vector<int> last(26);
        for(int i=0; i<n; i++) last[s[i]-'a'] = i;

        vector<int> inString(26, false);
        string str;
        for(int i=0; i<n; i++){
            char ch = s[i];

            // if already in string -> then skip
            if(inString[ch-'a']) continue;

            // remove the larger elements which will occur latter in the string
            while(!str.empty() && str.back() > ch && last[str.back()-'a']>i){
                inString[str.back()-'a'] = false;
                str.pop_back();
            }

            str.push_back(ch);
            inString[ch-'a'] = true;
        }
        return str;
    }
};