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
    int helper(TreeNode* root){
        // base case
        if(root == NULL) return 0;

        int leftheight = helper(root->left);
        int rightheight = helper(root->right);
        return max(leftheight, rightheight) + 1;
    }
    int maxDepth(TreeNode* root) {
        // base cases
        if(root == NULL) return 0;
        
        return helper(root);
    }
};