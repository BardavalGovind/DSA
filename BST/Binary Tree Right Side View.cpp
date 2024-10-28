/*
APPROACH with no extra space

Maintain an array / vector.

TRAVERSAL -> ROOT ->RIGHT -> LEFT This is the way traversal is done in array so that rightmost node at i level is visited first.

When at i level, check in array/vector, if there is an element already present at indexi in the array.
[ index represents the level in tree ]->[element at index i is rightmost node at level i]

If at that level, element is present,, just continue the traversal.

Else if no element is present at index i -> add that node to answer [res] at the i index.
*/

void rightSide(TreeNode *root,int level,vector<int>&ans){
    if(!root){return;}
    if(level==ans.size()){
        ans.push_back(root->val);
    }
    
    rightSide(root->right,level+1,ans);
        rightSide(root->left,level+1,ans);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightSide(root,0,ans);
        return ans;
    }