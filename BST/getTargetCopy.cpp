class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL) {
            return NULL;
        }
        
        if (original == target) {
            return cloned;
        }
        
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left != NULL) {
            return left;
        } else {
            return getTargetCopy(original->right, cloned->right, target);
        }
    }
};
