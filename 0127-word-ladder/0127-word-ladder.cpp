class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        unordered_map<string, bool> visited;
        queue<string> q;

        int level = 1;

        q.push(beginWord);
        visited[beginWord] = true;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                string curr = q.front();
                q.pop();

                // check for ans
                if(curr == endWord) return level;

                for(int i=0; i<curr.size(); i++){
                    for(int j=0; j<=25; j++){
                        
                        string next = curr.substr(0, i) + char('a'+j) + curr.substr(i+1);
                        
                        if(dict.count(next) && !visited[next]){
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};