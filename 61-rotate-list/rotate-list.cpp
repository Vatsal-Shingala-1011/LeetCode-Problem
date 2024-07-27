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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int len=1;
        ListNode* temp=head;
        while(temp->next!=NULL) temp=temp->next,len++;
        k=k%len;
        if(k==0) return head;
        ListNode* front=head;
        ListNode* back=head;
        int cnt=k;
        while(cnt--) front=front->next;
        while(front->next!=NULL){
            front=front->next;
            back=back->next;
        }
        ListNode* ans=back->next;
        back->next=NULL;
        front->next=head;
        return ans;
    }
};