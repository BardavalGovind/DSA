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
    int maxDepthHelper(TreeNode* root) {
        // if(root == NULL) return 0;
        return root == NULL ? 0 : max(maxDepthHelper(root->left), maxDepthHelper(root->right)) + 1;
        // int leftDepth = maxDepthHelper(root->left);
        // int rightDepth = maxDepthHelper(root->right);
        // int maxDepth = max(leftDepth, rightDepth) + 1;
        // return maxDepth;
    }
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root);
    }
};