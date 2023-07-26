class Solution {
public:
 bool solve(vector<int>& dist, double hour, int n, int mid) {
        double totalTime = 0;
        for (int i = 0; i < n - 1; i++) {
            totalTime += ceil((double)dist[i] / mid);
        }
        totalTime += (double)dist[n - 1] / mid;
        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int t=hour;
        if(n-1>t) return -1;
        int s=0,e=1e9;
        bool f=1;
        while(s<=e){
            int mid=s+((e-s)/2);
            if(mid==0 && f){
                f=0;
                mid=1;
            }
            if(solve(dist,hour,n,mid)){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        if(s>1e7) return -1;
        return s;
    }
};

