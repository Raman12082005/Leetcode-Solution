/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // base cases
        if(root == NULL) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool lefttoright = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                int idx = (lefttoright) ? i : (size -i-1);
                level[idx] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            lefttoright = !lefttoright;
            ans.push_back(level);
        }
        return ans;
    }
};