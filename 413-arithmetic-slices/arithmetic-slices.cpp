class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        vector<int> ans;
        int i=0;
        while(i<=n-3){
            int cnt=2;
            while(i<n-2 && nums[i]-nums[i+1]==nums[i+1]-nums[i+2]){
                cnt++;
                i++;
            }
            if(cnt!=2) ans.push_back(cnt);
            i++;
        }
        int sum=0;
        for(int x:ans){
            cout<<x<<" ";
            sum+= ((x*(x+1))/2) - x - x + 1;
        }
        return sum;
    }
};