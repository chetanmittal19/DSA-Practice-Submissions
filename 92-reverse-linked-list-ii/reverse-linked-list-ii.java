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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // Method 1 (Iterative) O(N)
        //the prev pointer is fixed at poition = left-1
        //curr and forw pointer will help in reversing the list
        ListNode dummy = new ListNode(0); // created dummy node
        dummy.next = head;
        ListNode prev = dummy; // intialising prev pointer on dummy node
        
        for(int i = 0; i < left - 1; i++)
            prev = prev.next; // adjusting the prev pointer on it's actual index
        
        ListNode curr = prev.next; // curr pointer will be just after prev
        // reversing
        for(int i = 0; i < right - left; i++){
            ListNode forw = curr.next; // forw pointer will be after curr
            curr.next = forw.next;
            forw.next = prev.next;
            prev.next = forw;
        }
        return dummy.next;

        // Method 2 (Using Stack) O(N)
        // if(left==right)
        //     return head;
        // ListNode head1=head;
        // ListNode finalhead=head;
        // Stack<Integer> st=new Stack<>();
        // int c=1;
        // while(c<left){
        //     head=head.next;
        //     c++;
        // }
        // int start=c;
        // while(c<=right){
        //     st.push(head.val);
        //     head=head.next;
        //     c++;
        // }
        // int cnt=1;
        // while(cnt<start){
        //     head1=head1.next;
        //     cnt++;
        // }
        // while(!st.isEmpty()){
        //     head1.val=st.pop();
        //     head1=head1.next;
        // }
        // return finalhead;
    }
}