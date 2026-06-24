class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size();
        vector<int> nums(4, 0);
        int blanck = 0;
        for(int i=0; i<n; i++){
            if(moves[i] == 'L') nums[0]++;
            else if(moves[i] == 'D') nums[1]++;
            else if(moves[i] == 'R') nums[2]++;
            else if(moves[i] == 'U') nums[3]++;
            else blanck++;
        }

        int hor = abs(nums[1] - nums[3]);
        int ver = abs(nums[0] - nums[2]);
        int ans = hor + ver + blanck;
        return ans;
    }
};