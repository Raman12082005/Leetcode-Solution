class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int n = s1.size();
        int m = s2.size();
        // base cases



        vector<vector<int>> res;
        int i=0;
        int j = 0;
        while(i<n && j<m){
            if(s1[i][0] == s2[j][0]){
                res.push_back({s1[i][0], s1[i][1] + s2[j][1]});
                i++;
                j++;
            }
            else if(s1[i][0] < s2[j][0]){
                res.push_back({s1[i][0], s1[i][1] + s2[j][1]});
                i++;
            }
            else{
                res.push_back({s2[j][0], s1[i][1] + s2[j][1]});
                j++;
            }
        }
        while(i<n){
            res.push_back({s1[i]});
            i++;
        }
        while(j<m){
            res.push_back({s2[j]});
            j++;
        }
        return res;
    }
};