class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int first = 0;
        string result = "";
        while(first < word1.size() && first < word2.size()){
            result += word1[first];
            result += word2[first];
            first++;
        }
        while(first < word1.size()){
            result += word1[first];
            first++;
        }
        while(first < word2.size()){
            result += word2[first];
            first++;
        }
        return result;
    }
};