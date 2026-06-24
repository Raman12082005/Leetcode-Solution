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