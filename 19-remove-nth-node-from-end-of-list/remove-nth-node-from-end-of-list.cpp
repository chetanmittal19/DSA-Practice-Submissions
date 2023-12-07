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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Method 1 [BruteForce]
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            temp = temp-> next;
            cnt++;
        }
        if(cnt==n){
            ListNode* newHead = head->next;
            head->next = NULL;
            delete head;
            return newHead;
        }
        int res = cnt-n; 
        temp = head;
        while(temp!=NULL){
            res--;
            if(res==0) break;
            temp = temp->next;
        }
        // now temp is pointing to node before the node to be deleted
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delNode->next = NULL;
        delete delNode;
        return head;

        // Method 2 [Optimised]
        // if(head==NULL) return head;
        // ListNode *fast = head;
        // for(int i=0; i<n; i++) fast = fast->next;

        // if(fast==NULL) return head->next; // It means n is equal to length of linkedlist
        // ListNode *slow = head;
        // while(fast->next!=NULL){
        //     fast = fast->next;
        //     slow = slow->next;
        // }
        // slow->next = slow->next->next;
        // return head;
    }
};