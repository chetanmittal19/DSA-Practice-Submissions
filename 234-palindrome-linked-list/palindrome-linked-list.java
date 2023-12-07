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
    public boolean isPalindrome(ListNode head) {
        // Method 1 [BruteForce, LinkedList/stack] O(N), O(N)

        // Method 2 [Optimised] O(N), O(1)
        // find the middle of the linked list and reverse the other half of the linked list and now check for palindrome
        // Note - If the interviewer ask not to modify the array then at the end, again reverse the second half to maintain orignal order(STRIVER)
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode newHead = reverse(slow.next);
        ListNode first = head, second = newHead;

        while(second!=null){
            if(first.val!=second.val) {
                reverse(newHead);
                return false;
            }
            first = first.next;
            second = second.next;
        }
        reverse(newHead);
        return true;
    }
    
    ListNode reverse(ListNode head){
        if(head==null || head.next==null) return head;
        
        ListNode curr = head;
        ListNode prev = null;
        
        while(curr!=null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}