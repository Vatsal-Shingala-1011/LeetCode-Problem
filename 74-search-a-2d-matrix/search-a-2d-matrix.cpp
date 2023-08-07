//solution 1 search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int row=mat.size();
        int col=mat[0].size();
        int size=row*col;
        int s=0,e=size-1,mid=s+((e-s)/2);
        int midele;
        while(s<=e){
            midele=mat[mid/col][mid%col];
            if(midele == tar){return true;}
            else if(midele < tar){ s=mid+1;}
            else{e=mid-1;}
            mid=s+((e-s)/2);
        }
    return false;
    }
};



//solution 2
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& mat, int tar) {
//     int i=0;
//     int n = mat[0].size();
//     int m = mat.size();
//     int j = n-1;

//     while(i>=0 and i<m and j>=0 and j<n){
        
//         if(mat[i][j]==tar) return 1;

//         else if(mat[i][j]>tar) j--;

//         else if(mat[i][j]<tar) i++;
//     }
//     return 0;

//     }
// };