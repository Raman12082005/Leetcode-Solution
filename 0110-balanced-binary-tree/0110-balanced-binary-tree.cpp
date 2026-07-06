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
bool ans = true;
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int leftheight = helper(root->left);
        int rightheight = helper(root->right);

        if(abs(leftheight - rightheight) > 1) ans = false;;
        
        return max(leftheight, rightheight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        // base case
        if(root == NULL) return true;

        helper(root);
        return ans;
    }
};