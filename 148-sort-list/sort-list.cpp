/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public:
    
    ListNode* sortList(ListNode* head) {

        //Method 1 O(NlogN), O(N)
        // if(head==NULL || head->next==NULL) return head;
        // vector<int> v;
        // ListNode *curr = head;
        // while(curr!=NULL){
        //     v.push_back(curr->val);
        //     curr=curr->next;
        // }
        // sort(v.begin(), v.end());
        // curr=head;
        // int i=0;
        // while(curr!=NULL){
        //     curr->val = v[i++];
        //     curr=curr->next;
        // }
        // return head;

        if(head==NULL || head->next==NULL) return head;

        ListNode *prev = NULL, *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        ListNode *head1=sortList(head);
        ListNode *head2=sortList(slow);
        return merge(head1, head2);
    }

    ListNode* merge(ListNode *left, ListNode *right){
        if(left==NULL) return right;
        if(right==NULL) return left;

        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                tail->next = left;
                left=left->next;
            } else {
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }

        if(left==NULL) tail->next=right;
        else tail->next=left;

        return head->next;
    }
};