class Solution {
public:
    long long dfs(int root, vector<vector<int>>& children, vector<int>& baseTime){
        //if leaf node
        if(children[root].empty()){
            return baseTime[root];
        }

        long long latest = LLONG_MIN;
        long long earliest = LLONG_MAX;

        for(auto child : children[root]){
            long long childfinish = dfs(child, children, baseTime);
            latest = max(latest, childfinish);
            earliest = min(earliest, childfinish);
        }
        return (2*latest - earliest) + baseTime[root];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> children(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            children[u].push_back(v);
        }
        return dfs(0, children, baseTime);
    }
};