class Solution {
private:
    void solve(string digits,string output,vector<string>& ans,int index,string mapping[10]){
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0'; //num=2
        string value = mapping[number];
        int size=value.length();
        for(int i=0;i<size;i++)
        {
            output.push_back(value[i]);
            solve(digits,output,ans,index+1,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) { //digits: containing digits from 2-9 
        vector<string> ans;
        string output;
        if(digits.length()==0){return ans;}
        int index=0;
        string mapping[10]={"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,ans,index,mapping);
        return ans;
    }
};