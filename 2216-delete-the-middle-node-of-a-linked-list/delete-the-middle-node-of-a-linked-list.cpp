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
        // Method 1 [BruteForce] O(2N), O(1)
        if(head==NULL || head->next==NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }

        int res = cnt/2;
        temp = head;
        while(temp!=NULL){
            res--;
            if(res==0) {
                ListNode* middle = temp->next;
                temp->next = temp->next->next;
                middle->next = NULL;
                delete middle;
                break;
            }
            temp = temp->next;
        }
        return head;

        // Method 2 [Optimised] O(N), O(1)
        // if(head==NULL || head->next==NULL) return NULL;
        // ListNode *prev=NULL, *slow = head, *fast = head;

        // while(fast!=NULL && fast->next!=NULL){
        //     prev=slow;
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // //slow will point to the node to be deleted and prev is the node before it
        // if(slow!=head) prev->next = slow->next;
        // else head = nullptr;

        // slow->next=NULL;
        // delete slow;
        // return head;
    }
};