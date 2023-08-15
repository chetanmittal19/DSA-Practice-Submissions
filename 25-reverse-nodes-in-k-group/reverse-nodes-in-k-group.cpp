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
        //Method 1 [Recursive] O(2N) = O(N), O(N)[For recursion stack]
        // here we first check if the given list contains atleast k elemnts or not. 
        // If we have k elements then we simply reverse those k elements and call recursive function for the 
        // remaining elements else we simply return the head
        // if(head==NULL || k==1) return head;
        // ListNode *curr = head;
        // for(int i=1; i<k; i++){
        //     if(curr->next==NULL) return head;
        //     curr = curr->next;
        // }
        // ListNode *remHead = curr->next;
        // curr->next = NULL;
        // reverse(head);
        // head->next=reverseKGroup(remHead, k);
        // return curr;

        //Method 2 [Iterative] O(N), O(1)
        if(head==NULL || k==1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *prev = dummy, *curr = dummy, *nex = dummy;
        int count = 0; //stores length of array
        while(curr->next!=NULL){ 
            curr=curr->next;
            count++;
        }

        while(count>=k){
            curr=prev->next;
            nex = curr->next;
            //here we are reversing in pairs one by one, instead of reversing entire k elements at once
            for(int i=1; i<k; i++){ //if we have to reverse k nodes then our reverse will always be k-1 times
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex=curr->next;
            }
            prev=curr;
            count-=k;
        }
        return dummy->next;
        

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