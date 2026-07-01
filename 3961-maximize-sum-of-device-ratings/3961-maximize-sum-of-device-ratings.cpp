class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        // base case
        if(m == 1) return *min_element(units[0].begin(), units[0].end());
        if(n == 1){
            long long ans = 0;
            for(int i=0; i<m; i++) ans += units[i][0];
            return ans;
        }


        vector<int> mini(m), secondmini(m);
        for(int i=0; i<m; i++){
            int first = INT_MAX, second = INT_MAX;
            int idx = -1;

            for(int j = 0; j<n; j++){
                if(first > units[i][j]){
                    first = units[i][j];
                    idx = j;
                }
            }
            for(int j=0; j<n; j++){
                if(j != idx && second > units[i][j]){
                    second = units[i][j];
                }
            }
            mini[i] = first;
            secondmini[i] = second;
        }

        int miniidx = 0;
        int val = secondmini[0];
        for(int i=1; i<m; i++){
            if(secondmini[i] < val){
                miniidx = i;
                val = secondmini[i];
            }
            else if(secondmini[i] == val){
                if(mini[i] < mini[miniidx]){
                    miniidx = i;
                    val = secondmini[i];
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<m; i++){
            if(miniidx != i){
                ans += secondmini[i];
            }
        }
        ans += *min_element(mini.begin(), mini.end());
        return ans;
    }
};