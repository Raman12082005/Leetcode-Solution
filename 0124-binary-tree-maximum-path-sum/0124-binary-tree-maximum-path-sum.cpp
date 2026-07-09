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
    int ans = INT_MIN;
    int helper(TreeNode* root){
        // base cases
        if(root == NULL) return 0;

        int leftpath = max(0, helper(root->left));
        int rightpath = max(0, helper(root->right));
        ans = max(ans, leftpath + rightpath + root->val);
        return max(leftpath, rightpath) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        // base cases
        if(root == NULL) return -1;

        ans = root->val;
        helper(root);
        return ans;
    }
};