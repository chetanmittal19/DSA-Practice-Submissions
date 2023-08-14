/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;

        ListNode *curr1 = headA, *curr2 = headB;
        int count1=0;
        while(curr1!=NULL){
            count1++;
            curr1=curr1->next;
        }

        int count2=0;
        while(curr2!=NULL){
            count2++;
            curr2 = curr2->next;
        }

        curr1=headA;
        curr2=headB;
        int diff=abs(count2-count1);
        if(count1>=count2){
            while(diff--!=0) curr1=curr1->next;
        } else while(diff--!=0) curr2=curr2->next;

        while(curr1!=NULL && curr2!=NULL){
            if(curr1==curr2) return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};