class Solution {
public:
    bool ispalindrome(int s,int e, string& str){
        while(s<e){
            if(str[s++] != str[e--]) return false;
        }
        return true;
    } 
    void solve(int index,string s, vector<string>& path, vector<vector<string>>& ans){
        if(index>=s.length()){
            ans.push_back(path);
            return;
        }
        for(int i=index; i<s.length();i++){
            if(ispalindrome(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s,path,ans);
                path.pop_back(); //& for path
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans);
        return ans;
    }
};