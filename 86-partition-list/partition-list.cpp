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
        if(head==NULL || head->next==NULL) return head;
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(0);
        ListNode *sTail = small, *lTail = large;
        
        ListNode *curr=head;
        while(curr!=NULL){
            if(curr->val<x){
                sTail->next = curr;
                sTail = sTail->next;
            } else {
                lTail->next = curr;
                lTail = lTail->next;
            }
            curr=curr->next;
        }

        lTail->next = NULL;
        sTail->next = large->next;
        large->next=NULL;
        delete large;
        return small->next;
    }
};