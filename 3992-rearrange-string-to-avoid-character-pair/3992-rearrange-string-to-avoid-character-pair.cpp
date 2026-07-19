class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size();
        // base case


        unordered_map<char, int> freq;
        for(auto ch : s) freq[ch]++;

        string t;
        int ycount = (freq.count(y)) ? freq[y] : 0;
        int xcount = (freq.count(x)) ? freq[x] : 0;
        for(int i=0; i<ycount; i++) t+=y;
        for(int i=0; i<xcount; i++) t+=x;

        for(auto it : freq){
            if(it.first == x || it.first == y) continue;

            int count = it.second;
            for(int i=0; i<count; i++) t+=it.first;
        }
        return t;
    }
};