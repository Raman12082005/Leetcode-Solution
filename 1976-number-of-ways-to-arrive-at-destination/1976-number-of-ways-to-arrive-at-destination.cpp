class Solution {
public:
    long long Mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // base cases


        unordered_map<int, list<pair<int, int>>> adjlist;
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adjlist[u].push_back({v, w});
            adjlist[v].push_back({u, w});
        }

        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        ways[0] = 1;
        dist[0] = 0;

        priority_queue<pair<long long, int> , vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {dist, node}
        pq.push({0, 0});

        while(!pq.empty()){
            auto currnodedist = pq.top().first;
            auto currnode = pq.top().second;
            pq.pop();

            if(currnodedist > dist[currnode]) continue;

            for(auto neighbour : adjlist[currnode]){
                if(currnodedist + neighbour.second < dist[neighbour.first]){
                    dist[neighbour.first] = currnodedist + neighbour.second;
                    pq.push({currnodedist + neighbour.second, neighbour.first});
                    ways[neighbour.first] = ways[currnode];
                }
                else if(currnodedist + neighbour.second == dist[neighbour.first]){
                    ways[neighbour.first] = (ways[neighbour.first] + ways[currnode]) % Mod;
                }
            }
        }
        return ways[n-1] % Mod;
    }
};