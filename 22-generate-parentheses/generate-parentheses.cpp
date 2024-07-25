class Solution {
public:
    void solve(int o,int c,int n,string& path,vector<string>& ans){
        if(o>n || c>n) return;
        if(o==n && c ==n) ans.push_back(path);
        if(o<n){ //opening 
            path.push_back('(');
            solve(o+1,c,n,path,ans);
            path.pop_back();
        }
        if(o>c){ //clossing 
            path.push_back(')');
            solve(o,c+1,n,path,ans);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int c=0,o=0;
        vector<string> ans;
        string path;
        solve(o,c,n,path,ans);
        return ans;
    }
};