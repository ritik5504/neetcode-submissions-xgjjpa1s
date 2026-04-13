class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        visited[i][j] = true;

        for(auto d : dir){
            int xi = i + d[0];
            int xj = j + d[1];

            if(xi >= 0 && xj >= 0 && xi < n && xj < m &&
               !visited[xi][xj] &&
               heights[xi][xj] >= heights[i][j]){
                
                dfs(xi, xj, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> paci(n, vector<bool>(m, false));
        vector<vector<bool>> atla(n, vector<bool>(m, false));

        // Pacific
        for(int i = 0; i < n; i++){
            dfs(i, 0, heights, paci);
        }
        for(int j = 0; j < m; j++){
            dfs(0, j, heights, paci);
        }

        // Atlantic
        for(int i = 0; i < n; i++){
            dfs(i, m-1, heights, atla);
        }
        for(int j = 0; j < m; j++){
            dfs(n-1, j, heights, atla);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(paci[i][j] && atla[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};