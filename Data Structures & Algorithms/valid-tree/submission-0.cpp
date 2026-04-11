class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;

        for(auto &nig:adj[node]){
            if(!visited[nig]){
                dfs(nig,adj,visited);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!= n-1)return false;
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<bool>visited(n,false);
        dfs(0,adj,visited);

        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;


    }
};
