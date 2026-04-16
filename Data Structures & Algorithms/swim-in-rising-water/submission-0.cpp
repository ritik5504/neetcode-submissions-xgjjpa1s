class Solution {
public:

    vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    int n;
    bool solve(vector<vector<int>>& grid,int i,int j,int t,vector<vector<bool>>&visited){
        if(i<0 || i>= n || j<0 || j>=n || grid[i][j]>t || visited[i][j]==true) return false;
        
        visited[i][j]=true;
        if(i==n-1 && j==n-1) return true;

        for(auto &d:dir){
            int a=i+d[0];
            int b=j+d[1];
            if(solve(grid,a,b,t,visited)){
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
       int l=grid[0][0],r=n*n-1;
       int res=0;

       while(l<=r){
        int mid=l+(r-l)/2;
        
         vector<vector<bool>>visited(n,vector<bool>(n,false));
         if(solve(grid,0,0,mid,visited)){
            res=mid;
            r=mid-1;
         }else{
            l=mid+1;

         }

       }
       return res;



        
    }
};
