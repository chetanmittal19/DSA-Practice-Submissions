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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        if(head->next->next==NULL){
            delete head->next;
            head->next=NULL;
            return head;
        }

        ListNode *prev=NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        //slow will point to the node to be deleted and prev is the node before it
        prev->next = slow->next;
        slow->next=NULL;
        delete slow;
        return head;
    }
};