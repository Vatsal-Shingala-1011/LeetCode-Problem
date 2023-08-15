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
    ListNode* partition(ListNode* head, int x) {
        ListNode* f=new ListNode(-1);
        ListNode* s=new ListNode(-1);
        ListNode* fptr=f;
        ListNode* sptr=s;
        ListNode* ptr=head;
        while(ptr!=NULL){
            if(ptr->val<x){
                fptr->next=ptr;
                fptr=fptr->next;
            }
            else{
                sptr->next=ptr;
                sptr=sptr->next;
            }
            ptr=ptr->next;
        }
        sptr->next=NULL;
        fptr->next=s->next;
        return f->next;
    }
};