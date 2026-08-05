class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // base cases


        unordered_map<int, list<int>> parent, adj;
        for(auto it : invocations){
            int u = it[0];
            int v = it[1];
            parent[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<bool> visited(n, false);
        vector<int> suspecious;

        stack<int> st;
        st.push(k);
        visited[k] = true;
        while(!st.empty()){
            int it = st.top();
            st.pop();
            suspecious.push_back(it);
            for(auto next : adj[it]){
                if(!visited[next]){
                    visited[next] = true;
                    st.push(next);
                }
            }
        }

        unordered_set<int> sus(suspecious.begin(), suspecious.end());
        bool canRemove = true;
        for(auto it : suspecious){
            for(auto x : parent[it]){
                if(!sus.count(x)){
                    canRemove = false;
                    break;
                }
            }
            if(!canRemove) break;
        }
        if(!canRemove){
            vector<int> ans;
            for(int i=0; i<n; i++) ans.push_back(i);
            return ans;
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!sus.count(i)) ans.push_back(i);
        }
        return ans;
    }
};