class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int l=0,r=row*col-1;

        int mid=l+(r-l)/2;

        while(l<=r){
            int ele=matrix[mid/col][mid%col];

            if(ele==target)return 1;
            else if(ele < target) l=mid+1;
            else{
                r=mid-1;

            }
            mid=l+(r-l)/2;

        }
        return 0;
        
    }
};
