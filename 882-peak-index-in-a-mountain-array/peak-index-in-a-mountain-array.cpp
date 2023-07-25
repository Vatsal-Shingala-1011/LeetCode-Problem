class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int s=0,l=n-1;
        int mid=s+((l-s)/2);
        while(s<l){
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                l=mid;
            }
            mid=s+((l-s)/2);
        }
        return mid;
    }
};
/////77777777