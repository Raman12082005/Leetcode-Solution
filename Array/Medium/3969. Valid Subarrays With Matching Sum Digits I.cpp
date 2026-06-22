/*
You are given an integer array nums and an integer digit x.
A subarray nums[l..r] is considered valid if the sum of its elements satisfies both of the following conditions:
The first digit of the sum is equal to x.
The last digit of the sum is equal to x.
Return the number of valid subarrays.

Example 1:
Input: nums = [1,100,1], x = 1
Output: 4
Explanation:
The valid subarrays are:
nums[0..0]: sum = 1
nums[0..1]: sum = 1 + 100 = 101
nums[1..2]: sum = 100 + 1 = 101
nums[2..2]: sum = 1
Thus, the answer is 4.

Example 2:
Input: nums = [1], x = 2
Output: 0
Explanation:
The only subarray is nums[0..0] with a sum of 1, which does not satisfy the conditions.
Thus, the answer is 0.

Constraints:
1 <= nums.length <= 1500
1 <= nums[i] <= 109
1 <= x <= 9 
*/

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        // base cases



        int count = 0;
        for(int i=0; i<n; i++){
            unsigned long long sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];

                int lastdigit = sum % 10;
                unsigned long long temp = sum;
                while(temp >= 10){
                    temp /= 10;
                }
                int firstdigit = temp;
                if(lastdigit == x && firstdigit == x){
                    count++;
                }
            }
        }
        return count;
    }
};
