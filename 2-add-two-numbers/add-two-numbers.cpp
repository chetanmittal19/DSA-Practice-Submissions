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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode *curr1=l1, *curr2=l2;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry=0;
        while(curr1!=NULL || curr2!=NULL || carry>0){
            int val = carry;
            if(curr1!=NULL) {
                val+= curr1->val;
                curr1=curr1->next;
            }
            if(curr2!=NULL) {
                val+=curr2->val;
                curr2=curr2->next;
            }
            tail->next=new ListNode(val%10);
            tail = tail->next;
            carry = (val>9) ? 1 : 0;
        }
        // if(carry==1) tail->next = new ListNode(1);
        return head->next;
    }
};