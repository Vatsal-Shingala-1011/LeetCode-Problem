class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<long long, vector<long long>> m;
        int n=nums.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            int x=nums[i];
            vector<int> temp;
            if(x==0){
                m[mapping[x]].push_back(x);
                continue;
            }
            while(x){
                temp.push_back(x%10);
                x/=10;
            }
            long long ans=0;
            for(int j=temp.size()-1;j>=0;j--){
                ans = (ans*10) + mapping[temp[j]];
            }
            m[ans].push_back(nums[i]);
        }

        for(auto itr:m){
            for(auto i:itr.second){
                v.push_back(i);
            }
        }
        return v;
    }
};