class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length(),i=0;
        if(n==1 || numRows==1) return s;
        string ans="";
        int j=0,jump=(numRows-1)*2;
        int f=jump,t=0;
        while(j<numRows){
            i=j;
            bool flag=false;
            while(i<n){
                ans+=s[i];
                if(f==0 || t==0) i+=jump;
                else{
                    if(!flag)flag=true,i+=f;
                    else{
                        flag=false,i+=t;
                    } 
                }
            }
            f-=2,t+=2,j++;
        }
        return ans;
    }
};