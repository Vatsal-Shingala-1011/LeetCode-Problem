class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(auto str: logs){
            if(str == "./"){
            }
            else if(str == "../"){
                if(!s.empty()) s.pop();
            }else {
                s.push(str);
            }
        }
        return s.size();
    }
};