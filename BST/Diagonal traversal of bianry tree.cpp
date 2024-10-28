/*
To Solve this problem, we will use queue data Structure.

We will follow the steps:

Push the root in the queue.
Now, till the queue is empty follow the following steps.
Pop the front element of the queue and check if it is 
null or not.
If it's not null, we will push the left child of the 
element (if not null)  in the queue.
We will push the element data in vector.
Replace the element with its right child.
Follow the steps tiff queue is not empty.
Now, the time-complexity will be O(n) as we have to 
iterate over all elements of the binary Tree.

The space complexity will be O(n) as we are using 
a queue to store the Nodes of binary Tree.
*/
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>ans;
   if(!root){return ans;}
    queue<Node*>q;
    q.push(root);
    Node *node=root;
    while(!q.empty()){
        node=q.front();q.pop();
        while(node){
            if(node->left){
                q.push(node->left);
            }
            ans.push_back(node->data);
            node=node->right;
        }
    }
   return ans;
}