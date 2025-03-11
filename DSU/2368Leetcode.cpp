class Solution {
public:
    unordered_set<int> st;
    vector<vector<int>> adj;
    int ans = 1;
    void dfs(int curr, int par){
        for(int nb : adj[curr]){
            if(nb == par) continue;
            if(!st.count(nb)){
                ans++;
                dfs(nb, curr);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adj.resize(n);
        for(int ele : restricted) st.insert(ele);
        if(st.count(0)) return 0;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, -1);
        return ans;
    }
};