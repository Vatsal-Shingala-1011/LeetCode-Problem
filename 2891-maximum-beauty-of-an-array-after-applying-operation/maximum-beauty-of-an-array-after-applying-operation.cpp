class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {//The beauty of the array is the len
        int n=nums.size();
        if(n==1)return 1;
        sort(nums.begin(), nums.end());
        if(n==1) return nums[0];
        int index=0,ans=0,cnt=1;
        for(int i=1;i<n;i++){
            if((nums[i]-k)<=(nums[index]+k)){
                cnt++;
                ans=max(ans,cnt);
            }
            else{
                cnt--;
                if(cnt==0) cnt=1,i++;
                index++;
                i--;
            }
        }
        if(ans==0) return 1;
        return ans;
    }
};

