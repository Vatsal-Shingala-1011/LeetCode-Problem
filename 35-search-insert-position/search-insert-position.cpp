class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1,mid=s+((e-s)/2); //sorted array of distinct integers 
        while(s<=e){
            if(target == nums[mid]) return mid;
            else if(nums[mid] > target) e = mid-1;
            else{
                s = mid + 1;
            }
            mid=s+((e-s)/2);
        }
        return mid;
    }
};
