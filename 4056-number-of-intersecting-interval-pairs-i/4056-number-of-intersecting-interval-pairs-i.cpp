class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // base cases


        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(!(intervals[i][1] < intervals[j][0])) ans++;
            }
        }
        return ans;
    }
};