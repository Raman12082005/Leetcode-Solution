class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<int>& req, vector<bool>& visited){
        // base cases

        visited[node] = true;
        for(auto neighbour : adj[node]){
            req[neighbour]--;
            if(req[neighbour] == 0) dfs(neighbour, adj, req, visited);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        // base cases


        unordered_map<int, list<int>> adj;
        vector<int> req(numCourses, 0);
        vector<bool> visited(numCourses, false);
        for(int i=0; i<n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            req[u]++;
        }
        for(int i=0; i<numCourses; i++){
            if(req[i] == 0 && !visited[i]){
                dfs(i, adj, req, visited);
            }
        }

        for(int i=0; i<req.size(); i++){
            if(req[i] != 0) return false;
        }
        return true;
    }
};