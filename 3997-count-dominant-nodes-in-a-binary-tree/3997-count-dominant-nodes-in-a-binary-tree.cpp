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
    int ans = 0;
    int helper(TreeNode* root){
        // base cases
        if(root == NULL) return 0;

        int leftdominant = helper(root->left);
        int rightdominant = helper(root->right);
        int maxi = max({root->val, leftdominant, rightdominant});

        if(root->val == maxi) ans++;
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        helper(root);
        return ans;
    }
};