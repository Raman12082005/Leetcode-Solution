class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        for(auto it : trust){
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }

        for(int person = 1; person<=n; person++){
            if(indegree[person] == n-1 && outdegree[person] == 0){
                return person;
            }
        }
        return -1;
    }
};