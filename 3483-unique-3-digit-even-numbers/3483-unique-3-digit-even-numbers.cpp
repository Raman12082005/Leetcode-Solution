class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        int n = digits.size();
        vector<int> freq(10, 0);
        for(int i=0; i<n; i++){
            freq[digits[i]]++;
        }

        for(int num = 100; num<1000; num++){
            if(num%2 == 1) continue;

            int x = num;
            vector<int> need(10, 0);

            need[x%10]++;
            x/=10;
            need[x%10]++;
            x/=10;
            need[x]++;

            bool ispossible = true;
            for(int i=0; i<10; i++){
                if(need[i] > freq[i]){
                    ispossible = false;
                    break;
                }
            }
            if(ispossible) ans++;
        }
        return ans;
    }
};