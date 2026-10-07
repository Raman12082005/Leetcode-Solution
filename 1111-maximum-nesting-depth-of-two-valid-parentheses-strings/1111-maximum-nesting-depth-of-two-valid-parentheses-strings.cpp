class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        // base cases


        vector<int> ans;
        int depth = 0;
        for(auto ch : seq){
            if(ch == '('){
                depth++;
                ans.push_back(depth%2);
            }
            else{
                ans.push_back(depth%2);
                depth--;
            }
        }
        return ans;
    }
};