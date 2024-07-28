class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt++;
            int x = nums[i][1];
            while(i<n && nums[i][0]<=x){
                x=min(x,nums[i][1]);
                i++;
            }
            i--;
        }
        return cnt;
    }
};