class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        const int MOD = 1e9+7;
        vector<int> pow(100001);
        pow[0] = 1;
        for(int i=1; i<100001; i++){
            pow[i] = pow[i-1] * 10LL % MOD;
        }
        vector<int> A(n+1, 0);
        vector<int> B(n+1, 0);
        vector<int> len(n+1, 0);

        for(int i=0; i<n; i++){
            int d = s[i] - '0';
            A[i+1] = A[i] + d;

            if(d){
                B[i+1] = (B[i] * 10LL + d) % MOD;
                len[i+1] = 1 + len[i];
            }
            else{
                B[i+1] = B[i];
                len[i+1] = len[i];
            }
        }

        vector<int> result;
        for(auto q : queries){
            int l = q[0];
            int r = q[1] + 1;

            long long sub = B[l] * 1LL * pow[len[r] - len[l]] % MOD;
            long long x = (B[r] - sub + MOD) % MOD;

            result.push_back((x * (A[r] - A[l])) % MOD);
        }
        return result;
    }
};