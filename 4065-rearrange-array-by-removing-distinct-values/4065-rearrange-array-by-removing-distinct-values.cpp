class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // base cases


        map<int, int> freq;
        vector<int> ans;
        for(auto it : nums) freq[it]++;

        while(freq.size() != 0){
            for(auto it = freq.begin(); it != freq.end(); ){
                ans.push_back(it->first);
                if(it->second == 1) it = freq.erase(it);
                else{
                    it->second--;
                    it++;
                }
            }
        }
        return ans;
    }
};