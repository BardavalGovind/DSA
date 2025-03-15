#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      // Function to return a list containing the DFS traversal of the graph.
      vector<int> ans;
      vector<int> vis;
      vector<vector<int>> Adj;
      void dfs(int src){
          vis[src] = 1;
          
          ans.push_back(src);
          for(int nb : Adj[src]){
              if(!vis[nb]){
                  dfs(nb);
              }
          }
      }
      vector<int> dfsOfGraph(vector<vector<int>>& adj) {
         int n = adj.size();
         Adj = adj;
         vis.resize(n, 0);
         for(int i=0; i<n; i++){
             if(!vis[i]){
                 dfs(i);
             }
         }
         return ans;
         
      }
  };