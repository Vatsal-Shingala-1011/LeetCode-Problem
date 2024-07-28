class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        vector<long long> ans;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int cnt=0;
            while(i<n && nums[i-1]!=nums[i])i++,cnt++;
            if(cnt!=0)ans.push_back(cnt+1);
        }
        long long sum=n;
        n=ans.size();
        for(int i=0;i<n;i++){
            long long n=ans[i];
            long long add=n%2==0 ? ((n/2)*(n+1))-n : (n*(((n+1)/2)))-n;
            sum+= add;
        }
        return sum;
    }
};