class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr = 0;
        int ans = 0;
        for(auto it : requests){
            ans += abs(curr-it);
            curr = it;
        }
        return ans;
    }
};