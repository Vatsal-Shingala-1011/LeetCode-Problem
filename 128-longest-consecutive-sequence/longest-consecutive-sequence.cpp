class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool>m;
        for(auto num: nums){
            m[num]=true;
        }
        int len,ans=0;
        for(auto num: nums){
            if(m.find(num-1) != m.end()) continue;
            len=1;
            num++;
            while(m.find(num) != m.end()){
                len++;
                num++;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};