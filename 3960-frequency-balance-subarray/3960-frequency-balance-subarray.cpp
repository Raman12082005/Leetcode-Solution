class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        for(int i=0; i<n; i++){
            unordered_map<int, int> freq;
            unordered_map<int, int> cntfreq;
            for(int j=i; j<n; j++){
                int x = nums[j];

                if(freq.count(x)){
                    cntfreq[freq[x]]--;
                    if(cntfreq[freq[x]] == 0) cntfreq.erase(freq[x]);
                }

                freq[x]++;
                cntfreq[freq[x]]++;

                bool check = false;
                if(freq.size() == 1){
                    check = true;
                }
                else if(cntfreq.size() == 2){
                    auto it = cntfreq.begin();
                    int f1 = it->first;
                    it++;
                    int f2 = it->first;

                    if(max(f1, f2) == 2 * min(f1, f2)){
                        check = true;
                    }
                }
                if(check) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};