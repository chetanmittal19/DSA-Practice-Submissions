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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;

        ListNode *curr = head;
        for(int i=1; i<k; i++){
            if(curr->next==NULL) return head;
            curr = curr->next;
        }
        ListNode *remHead = curr->next;
        curr->next = NULL;
        reverse(head);
        head->next=reverseKGroup(remHead, k);
        return curr;
    }

    void reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr!=NULL){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
    }
};