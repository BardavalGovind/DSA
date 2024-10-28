class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> sol;
        postorder(root, sol);
        return sol;
    }
    void postorder(TreeNode* root, vector<int>& sol) {
        if (!root)
            return;
        postorder(root->left, sol);
        postorder(root->right, sol);
        sol.push_back(root->val);
    }
};