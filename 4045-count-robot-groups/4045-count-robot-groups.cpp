class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        // base cases


        int right = n-1;
        int groups = 1;
        for(int i=n-2; i>=0; i--){
            bool merge = false;
            long long gap = position[i+1] - position[i];

            // case 1
            if(gap <= distance) merge = true;

            // case 2
            if(!merge && speed[i] > speed[right]){
                merge = true;
            }

            if(!merge){
                groups++;
                right = i;
            }
        }
        return groups;
    }
};