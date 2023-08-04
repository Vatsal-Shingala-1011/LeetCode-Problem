class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        if(n==0)return true;
        vector<bool> memo(n+1,false);
        memo[0]=true;
        for(int i=0;i<n;i++){
        if(memo[n]==true) return true;//for early break
            if(memo[i]==true){
                for(auto word: wordDict){
                    int len=word.length();
                    string str=s.substr(i,len);
                    if(str.find(word)==0){
                        memo[i+len]=true;
                    }
                }
            }
        }
        if(memo[n]==true) return true;
        return false;
    }
};