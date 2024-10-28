
TreeNode* solve(int instart,int inend,vector<int>&inorder, int poststart,int postend,vector<int>&postorder, map<int,int>&mpp){
        if(instart>inend || poststart>postend){
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[postend]);
        int i=mpp[postorder[postend]];
        int len=i-instart;
        root->left=solve(instart,i-1,inorder,poststart,poststart+len-1,postorder,mpp);
        root->right=solve(i+1,inend,inorder,poststart+len,postend-1,postorder,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=inorder.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return solve(0,n-1,inorder,0,n-1,postorder,mpp);
    }
	/*
    inorder   = [4 2 5 1 6 3 7]
    postorder = [4 5 2 6 7 3 1]

    So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
    so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

    using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
    [4 5 2] and [6 7 3]


    1st Phase=>        
	                   1

                   /        \

                [4 2 5]   [6 3 7]       <= inorder array
                [4 5 2]   [6 7 3]       <= postorder array

Now we have new freash problem like need to make tree by using inorder = [4 2 5] && postorder =  [4 5 2] for left subtree 
AND inorder = [6 3 7] && postorder = [6 7 3] for right  subtree 
**now same process we need to do again and again  until One Of the array dose not got empty
Rest of the Process show in a diagram Form :)

    2nd Phase =>
                           1

                      /        \
                     2          3
                [4]    [5]   [6]   [7]       <= inorder array
                [4]    [5]   [6]   [7]       <= postorder array


3rd Phase =>  
	             1

               /    \
              2      3
 
            /  \    /  \             <==== Answer
 
           4    5  6    7 

	*/