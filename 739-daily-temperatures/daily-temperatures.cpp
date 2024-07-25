class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> s; // ele, index
        int n=temp.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first<=temp[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=0;
                s.push({temp[i],i});
            }else{
                ans[i]=s.top().second - i;
            }
            s.push({temp[i],i});
        }
        return ans;
    }
};