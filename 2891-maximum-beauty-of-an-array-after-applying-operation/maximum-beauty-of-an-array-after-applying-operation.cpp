class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int cnt=1,n=nums.size();
        if(n==1)return 1;
        sort(nums.begin(), nums.end());
        int index=0,ans=0;
        if(n==1) return nums[0];
        for(int i=1;i<n;i++){
            if((nums[i]-k)<=(nums[index]+k)){
                cnt++;
                ans=max(ans,cnt);
                // cout<<" if "<<nums[i]<<endl;
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

