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
        // Method 1 [Recursion] O(n), O(h)
        // if(root == null) return;
        // TreeNode dummy = new TreeNode(0);
        // prev = dummy;
        // flattenHelper(root);
        // prev.left = null;

        // Method 2 [Iterative, Stack] O(n), O(n)
        if(root==null) return;
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        while(!st.isEmpty()) {
            TreeNode curr = st.pop();
            if(curr.right!=null) st.push(curr.right);
            if(curr.left!=null) st.push(curr.left);
            if(!st.isEmpty()) curr.right = st.peek();
            curr.left = null;
        }

        // Method 3 [Iterative, similar to morris traversal] O(2n), O(1)
        // STRIVER: https://youtu.be/sWf7k1x9XR4
        // TreeNode curr = root;
        // while(curr!=null) {
        //     if(curr.left!=null) {
        //         TreeNode prev = curr.left;
        //         while(prev.right!=null) prev = prev.right;
        //         prev.right = curr.right;
        //         curr.right = curr.left;
        //     }
        //     curr.left = null;
        //     curr = curr.right;
        // }
        // curr = root;
    }

    // private void flattenHelper(TreeNode root) {
    //     if(root == null) return;
    //     TreeNode rightSubTree = root.right;
    //     prev.left = null;
    //     prev.right = root;
    //     prev = root;
    //     flattenHelper(root.left);
    //     flattenHelper(rightSubTree);
    // }
}