class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=i;
            while(num!=0 & num%5==0){
                ans++;
                num=num/5;
            }
        }
        return ans;
    }
};