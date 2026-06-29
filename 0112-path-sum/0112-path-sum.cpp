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
    bool found = false;
    void preorder(TreeNode* root, int target, int& sum){
        // base cases
        if(found) return;
        if(root == NULL) return;

        sum += root->val;

        if(root->left == NULL && root->right == NULL && sum == target) found = true;
        
        preorder(root->left, target, sum);
        preorder(root->right, target, sum);
        
        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int target){
        int sum = 0;
        preorder(root, target, sum);

        return found;
    }
};