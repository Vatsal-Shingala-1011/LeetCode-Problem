class Solution {//if sorted given then index i=0 and j=n-1 if sum>arr[i]+arr[j] j-- else i++
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.count(target-nums[i])){ //if required num is in map
                return {m[target-nums[i]] , i}; //give index of that and 
            }                                  //currunt index
            m[nums[i]]=i;
        }
        return{};
    }
};