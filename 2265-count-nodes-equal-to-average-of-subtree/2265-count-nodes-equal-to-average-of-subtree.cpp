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
    int cnt = 0;
    vector<int> helper(TreeNode* root){
        // base case
        if(root == NULL) return {0, 0};

        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        int sum = root->val + left[0] + right[0];
        int nodecount = 1 + left[1] + right[1];
        if(root->val == sum/nodecount) cnt++;

        return {sum, nodecount};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return cnt;
    }
};