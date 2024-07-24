class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) { //tabulation 100
        map<int,vector<vector<int>>> memo; //map of list: index -> vec
        memo[0]={{}};
        for(int i=0;i<target;i++){
            for(auto num: nums){
                if(!memo[i].empty() && i+num<=target){
                    for(auto vec_vec: memo[i]){
                        vec_vec.push_back(num);
                        sort(vec_vec.begin(),vec_vec.end());
                        memo[i+num].push_back(vec_vec);
                    }
                }
            }   
        }
        set<vector<int>> s(memo[target].begin(), memo[target].end());
        return vector<vector<int>>(s.begin(), s.end());
    }
};