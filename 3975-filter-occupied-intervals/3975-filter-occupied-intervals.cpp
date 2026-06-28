class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();
        // base case



        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];
        vector<vector<int>> result;
        for(int i=1; i<n; i++){
            if(occupiedIntervals[i][0] <= end + 1){
                end = max(end, occupiedIntervals[i][1]);
            }
            else{
                result.push_back({start, end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
        }
        result.push_back({start, end});

        int m = result.size();
        for(int i=0; i<m; i++){
            // handling 4 cases
            if(result[i][0] < freeStart && result[i][1] >= freeStart && result[i][1] <= freeEnd){
                result[i][1] = freeStart-1;
            }
            else if(result[i][0] <= freeEnd && result[i][0] >= freeStart && result[i][1] > freeEnd){
                result[i][0] = freeEnd+1;
            }
            else if(result[i][0] >= freeStart && result[i][1] <= freeEnd){
                result.erase(result.begin() + i);
                i--;
                m--;
            }
            else if(result[i][0] < freeStart && result[i][1] > freeEnd){
                int last = result[i][1];
                result[i][1] = freeStart - 1;
                result.insert(result.begin()+i+1, {freeEnd+1, last});
                i++;
                m++;
            }
        }

        return result;
    }
};