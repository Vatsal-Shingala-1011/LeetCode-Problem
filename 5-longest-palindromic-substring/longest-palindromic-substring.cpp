class Solution {
public:
    int start=0,end=0;
    void solve(string s,int left,int right,int len){
        int res=len;
        while(left>=0 && right<=s.length() && s[left]==s[right]){
            res=res+2;
            left--;
            right++;
        }
        if(res>end-start){
            start = left+1;
            end = right-1;
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();   
        if(n<=1) return s;
        for(int i=0;i<s.length();i++){
            solve(s,i-1,i+1,1);
            if(i+1<n && s[i]==s[i+1]) solve(s,i-1,i+2,2);
        }
        return s.substr(start, end - start + 1);
    }
};