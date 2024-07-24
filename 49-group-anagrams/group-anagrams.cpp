class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted;
        for(auto str : strs){
            sort(str.begin(),str.end());
            sorted.push_back(str);
        }
        int n = strs.size();
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            vector<string> temp;
            if(sorted[i]=="*") continue;
            temp.push_back(strs[i]);
            for(int j=i+1;j<n;j++){
                if(sorted[i]==sorted[j]){
                    sorted[j] = "*";
                    temp.push_back(strs[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};