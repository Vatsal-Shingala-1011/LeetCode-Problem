class Solution {
public:
    bool check(unordered_map<char,int>& m){
        for(auto itr:m){
            if(itr.second !=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        for(auto ch:p){
            m[ch]++;
        }
        int len_p=p.length(), len_s=s.length();
        for(int i=0;i<len_p;i++){
            m[s[i]]--;
        }
        int i=0,j=len_p;
        vector<int> ans;
        while(j<=len_s){
            if(check(m)) ans.push_back(i); 
            m[s[i]]++;
            if(j<len_s) m[s[j]]--;
            i++;
            j++;
        }
        return ans;
    }
};