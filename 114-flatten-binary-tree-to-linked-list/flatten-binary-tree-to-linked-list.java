/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    private TreeNode prev;
    public void flatten(TreeNode root) {
        // Method 1 [Recursion] O(N)
        if(root == null) return;
        TreeNode dummy = new TreeNode(0);
        prev = dummy;
        flattenHelper(root);
        prev.left = null;

        // Method 2 [Iterative] O(N)
        // if(root==null) return;
        // Stack<TreeNode> st = new Stack<>();
        // st.push(root);
        // TreeNode temp = new TreeNode(0);
        // TreeNode tail = temp;
        // while(!st.isEmpty()) {
        //     TreeNode front = st.pop();
        //     while(front!=null) {
        //         if(front.right!=null) st.push(front.right);
        //         tail.right = front;
        //         tail.left = null;
        //         tail = tail.right;
        //         front = front.left;
        //     }
        // }

        // tail.left = null;
    }

    private void flattenHelper(TreeNode root) {
        if(root == null) return;
        TreeNode rightSubTree = root.right;
        prev.left = null;
        prev.right = root;
        prev = root;
        flattenHelper(root.left);
        flattenHelper(rightSubTree);
    }
}