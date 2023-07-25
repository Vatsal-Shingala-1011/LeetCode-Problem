class Solution {//done
public://make space optimum to O(n)
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int maxi=0;
        unordered_map <int,int> memo[n+1];//or can use vector of unordered map
                   // min,diff
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int cnt=1;
                if(memo[j].count(diff))
                    cnt=memo[j][diff];
                memo[i][diff]=1+cnt;
                maxi=max(maxi,memo[i][diff]);
            }
        }
        return maxi;
    }
};