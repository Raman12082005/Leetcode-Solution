class Solution {
public:
    void helper(int node, unordered_map<int, list<int>>& adj, vector<int>& visited){
        int n = visited.size();
        visited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                helper(neighbour, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // base cases


        unordered_map<int, list<int>> adj;
        vector<int> visited(n, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;

                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int proviences = 0;
        for(int i=0;i<n; i++){
            if(!visited[i]){
                proviences++;
                helper(i, adj, visited);
            }
        }
        return proviences;
    }
};