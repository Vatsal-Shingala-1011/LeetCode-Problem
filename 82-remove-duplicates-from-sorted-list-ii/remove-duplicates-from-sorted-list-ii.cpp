/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* back=head;
        ListNode* front=head->next;
        ListNode* pre_back=new ListNode(-1);
        ListNode* ans=pre_back;
        pre_back->next=back;
        while(front!=NULL){
            int cnt=0; //if cnt==0 then only take front
            while(front!=NULL && back->val == front->val){
                cnt++; 
                front=front->next;
            }
            if(cnt==0)pre_back=pre_back->next;
            else{
                pre_back->next=front;
            }
            back=front;
            if(front!=NULL)front=front->next;
        }
        return ans->next;
    }
};