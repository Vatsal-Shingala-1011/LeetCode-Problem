bool comparator(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1];  // Compare based on the second column (index 1)
}
class Solution { //daily challenge submit without solve
public:

    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n=v.size();
        if(n<=1) return 0;
        sort(v.begin(),v.end(),comparator);
        int ans=0;
        pair<int,int> prev={v[0][0],v[0][1]};
        for(int i=1;i<n;i++){
            if(v[i][0]<prev.second) ans++;
            else{
                prev={v[i][0],v[i][1]};
            }
        }
        return ans;
    }
};