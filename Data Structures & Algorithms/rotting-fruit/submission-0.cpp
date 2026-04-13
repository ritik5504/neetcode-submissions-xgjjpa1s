class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        int count=0;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<int> dir = {0, 1, 0, -1, 0};

        while(!q.empty() && fresh>0){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto[x,y]=q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int dx=x+dir[d];
                    int dy=y+dir[d+1];

                    if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]==1 ){
                        grid[dx][dy]=2;

                        q.push({dx,dy});
                        fresh--;

                    }
                }
            }
            count++;
        }
        return fresh==0 ? count : -1;
        
    }
};