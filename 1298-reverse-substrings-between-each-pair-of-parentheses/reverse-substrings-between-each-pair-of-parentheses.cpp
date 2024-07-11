class Solution {
public:
    string reverseParentheses(string str) {
        stack<char> s;
        queue<char> q;
        for(auto ch:str){
            if(ch != ')') s.push(ch);
            else{
                while(s.top() != '('){
                    q.push(s.top());
                    s.pop();
                }
                s.pop();
                while(!q.empty()){
                    s.push(q.front());
                    q.pop();
                }
            }
        }
        string ans = "";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};