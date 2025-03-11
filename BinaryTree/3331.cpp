class Solution {
public:
    vector<int> parentNodes;
    string characters;
    vector<int> updatedParent;
    vector<vector<int>> adj;
    vector<int> SubtreeSizes;

    void determineNewParent(int node){
        int currentParent = parentNodes[node];
        while(currentParent != -1 && characters[currentParent] != characters[node]){
            currentParent = parentNodes[currentParent];
        }
        updatedParent[node] = (currentParent != -1) ? currentParent : parentNodes[node];
    }

    void calculateSubtreeSizes(int node){
        SubtreeSizes[node] = 1;
        for(int nb : adj[node]){
            if(nb == updatedParent[node]) continue;
            calculateSubtreeSizes(nb);
            SubtreeSizes[node] += SubtreeSizes[nb];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        characters = s;
        parentNodes = parent;
        updatedParent.resize(n, -1);
        SubtreeSizes.resize(n, 0);
        adj.resize(n);

        for(int i=0; i<n; i++){
            determineNewParent(i);
        }

        for(int node=0; node<n; node++){
            int newParent = updatedParent[node];
            if(newParent != -1){
                adj[newParent].push_back(node);
                adj[node].push_back(newParent);
            }
        }

        calculateSubtreeSizes(0);
        for(int ele : updatedParent){
            cout<<ele<<" ";
        }
        cout<<endl;
        return SubtreeSizes;
    }
};