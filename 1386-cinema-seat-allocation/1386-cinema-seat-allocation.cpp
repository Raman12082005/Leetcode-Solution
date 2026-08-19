class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> arr;
        for(auto seats : reservedSeats){
            int row = seats[0];
            int col = seats[1];

            if(arr.find(row) == arr.end()){
                arr[row] = vector<int>(11, 0);
            }
            arr[row][col] = -1;
        }

        int cnt =  2 * (n - arr.size());
        for(auto it : arr){
            auto seats = it.second;

            bool firstblock = false;
            if(seats[2] == 0 && seats[3] == 0 && seats[4] == 0 && seats[5] == 0){
                firstblock = true;
                cnt++;
            }
            bool secblock = false;
            if(seats[6] == 0 && seats[7] == 0 && seats[8] == 0 && seats[9] == 0){
                secblock = true;
                cnt++;
            }
            if(!firstblock && !secblock){
                if(seats[4] == 0 && seats[5] == 0 && seats[6] == 0 && seats[7] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};