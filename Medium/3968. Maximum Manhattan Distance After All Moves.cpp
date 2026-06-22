/*
You are given a string moves consisting of the characters 'U', 'D', 'L', 'R', and '_'.
Starting from the origin (0, 0), each character represents one move on a 2D plane:
'U': Move up by 1 unit.
'D': Move down by 1 unit.
'L': Move left by 1 unit.
'R': Move right by 1 unit.
'_': Can be independently replaced with any one of 'U', 'D', 'L', or 'R'.
Return the maximum Manhattan distance from the origin that can be achieved after all moves have been performed.

Example 1:
Input: moves = "L_D_"
Output: 4
Explanation:
One optimal choice is:
'L': (0, 0) -> (-1, 0)
'_' treated as 'D': (-1, 0) -> (-1, -1)
'D': (-1, -1) -> (-1, -2)
'_' treated as 'L': (-1, -2) -> (-2, -2)
The final Manhattan distance from the origin is |0 - (-2)| + |0 - (-2)| = 4.

Example 2:
Input: moves = "U_R"
Output: 3
Explanation:
One optimal choice is:
'U': (0, 0) -> (0, 1)
'_' treated as 'U': (0, 1) -> (0, 2)
'R': (0, 2) -> (1, 2)
The final Manhattan distance from the origin is |0 - 1| + |0 - 2| = 3.

Constraints:
1 <= moves.length <= 105
moves consists of only 'U', 'D', 'L', 'R', and '_'.
*/

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
