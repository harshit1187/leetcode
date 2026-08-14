class Solution {
public:
    int findmaxindex(vector<vector<int>> &mat,int m,int n,int col){
        int maxvalue=INT_MIN;
        int idx=-1;
        for(int i=0;i<m;i++){
            if(mat[i][col]>maxvalue){
                maxvalue=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
           int m=mat.size();
           int n=mat[0].size();
           int low=0;
           int high=n-1;
           while(low<=high){
                int mid=low+(high-low)/2;
                int maxrowidx=findmaxindex(mat,m,n,mid);
                int left=mid-1>=0?mat[maxrowidx][mid-1]:-1;
                int right=mid+1<n?mat[maxrowidx][mid+1]:-1;
                if(mat[maxrowidx][mid]>left && mat[maxrowidx][mid]>right)
                    return {maxrowidx,mid};
                else if(mat[maxrowidx][mid]<left)
                    high=mid-1;
                else
                    low=mid+1;
           }
           return{-1,-1};
      }
};