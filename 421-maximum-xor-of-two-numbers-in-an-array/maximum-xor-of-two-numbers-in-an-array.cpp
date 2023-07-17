class Solution {
public:
    struct TrieNode{
        TrieNode* zero;
        TrieNode* one;
    };
    void insert(TrieNode* root,int n){
        TrieNode* cur=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;
            if(bit==0){
                if(cur->zero==NULL){
                    TrieNode* newNode =new TrieNode();
                    cur->zero =newNode;
                }
                cur=cur->zero;
            }
            else{
                if(cur->one==NULL){
                    TrieNode* newNode=new TrieNode();
                    cur->one=newNode;
                }
                cur=cur->one;
            }
        }
    }
    int findMaxXor(TrieNode* root,int n){
        TrieNode* cur=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;
            if(bit==1){
                if(cur->zero!=NULL){
                    ans+=(1<<i);
                    cur=cur->zero;
                }else{
                    cur=cur->one;
                }
            }
            else{
                if(cur->one!=NULL){
                    ans+=(1<<i);
                    cur=cur->one;
                }else{
                    cur=cur->zero;
                }
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            insert(root,nums[i]);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,findMaxXor(root,nums[i]));
        }
        return ans;
    }
};