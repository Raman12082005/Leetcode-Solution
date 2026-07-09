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
    bool helper(TreeNode* p, TreeNode* q){
        // base cases
        if(p == NULL || q == NULL) return p==q;

        bool leftsubtree = helper(p->left, q->left);
        bool rightsubtree = helper(p->right, q->right);

        return (leftsubtree && rightsubtree && (p->val == q->val));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};