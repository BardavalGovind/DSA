/*
we create public field cnt to count avg that
 equals to root value of each subtree, 
 next we write recursive function that will be called 
 recursevly on left and right nodes. when we traverse 
 to leafs we and start to ascend, we will calculate sum
  of subtree and count of nodes in subtree, and 
  calculate average of subtree if it equals to 
  root value of current binary subtree, then we 
  increment cnt, at the end return cnt number
*/
class Solution {
public:
	int cnt=0;
	pair<int,int> solve(TreeNode *root){
		if(!root){
			return {0,0};
		}
		pair<int,int> lh=solve(root->left);
		pair<int,int> rh=solve(root->right);
		int sum=root->val+lh.first+rh.first;
		int num=lh.second+rh.second+1;
		if((sum/num)==root->val){
			cnt++;
		}
		return {sum,num};
	}
    int averageOfSubtree(TreeNode* root) {
        // int cnt=0,num=1;
        solve(root);
        return cnt;
    }
};