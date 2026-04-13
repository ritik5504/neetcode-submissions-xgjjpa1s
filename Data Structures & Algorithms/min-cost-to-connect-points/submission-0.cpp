class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool>visited(n,false);
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        int total=0;

        for(int i=0;i<n;i++){
            int u=-1;

            for(int j=0;j<n;j++){
                if(!visited[j] && (u==-1 || dist[j]<dist[u])){
                    u=j;
                }
            }
            visited[u]=true;
            total += dist[u];

            for(int v=0;v<n;v++){
                int cost = abs(points[u][0] - points[v][0]) +
                abs(points[u][1] - points[v][1]);

                if(cost<dist[v]){
                    dist[v]=cost;
                }
            }
            
        }
        return total;
        
    }
};
