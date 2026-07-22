class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int colour = image[sr][sc];
        // base cases
        if(colour == color) return image;

        vector<int> nx = {1, -1, 0, 0}, ny = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int, int> it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(int i=0; i<4; i++){
                int dx = r + nx[i];
                int dy = c + ny[i];
                if(dx>=0 && dx<m && dy>=0 && dy<n && image[dx][dy] == colour){
                    image[dx][dy] = color;
                    q.push({dx, dy});
                }
            }
        }
        return image;
    }
};