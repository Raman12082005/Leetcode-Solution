class Solution {
public:
    void constructLPS(vector<int>& lps, string pattern){
        int n = pattern.size();
        int i=1, len = 0;
        while(i<n){
            if(pattern[i] != pattern[len]){
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
            else{
                len++;
                lps[i] = len;
                i++;
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        vector<int>lps(n, 0);

        constructLPS(lps, needle);

        int i=0, j=0;
        while(i<m){
            if(haystack[i] == needle[j]){
                i++;
                j++;

                if(j == n){
                    return i-j;
                }
            }
            else{
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};