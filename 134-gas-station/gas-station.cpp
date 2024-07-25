class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr=0,req=0,start=0,n=cost.size();
        for(int i=0;i<n;i++){
            curr+=gas[i];
            if(curr<cost[i]){
                req= req + cost[i]-curr;
                start=i+1;
                curr=0;
                continue;
            }
            curr-=cost[i];
        }
        if(curr>=req) return start;
        return -1; 
    }
};