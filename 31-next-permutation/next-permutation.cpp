class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        bool flag=true;
        for(int i=n-2;i>=0;i--){
            pq.push(nums[i+1]);
            if(nums[i]<nums[i+1]){
                pq.push(nums[i]);
                int temp=nums[i],ind=i;
                i++;
                while(!pq.empty()){
                    if(pq.top()>temp && flag){
                        nums[ind]=pq.top();
                        pq.pop();
                        flag=false;
                        continue;
                    }
                    nums[i++]=pq.top();
                    pq.pop();
                }
                return;
            }
        }
        pq.push(nums[0]);
        if(flag){
            int i=0;
            while(!pq.empty()){
                nums[i++]=pq.top();
                pq.pop();
            }
        }
    }
};