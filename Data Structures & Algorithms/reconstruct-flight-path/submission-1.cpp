class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string u){
        while(!adj[u].empty()){
            string v=adj[u].top();
            adj[u].pop();
            dfs(v);
        }
        result.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto &e:tickets){
            adj[e[0]].push(e[1]);
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;

        
    }
};
