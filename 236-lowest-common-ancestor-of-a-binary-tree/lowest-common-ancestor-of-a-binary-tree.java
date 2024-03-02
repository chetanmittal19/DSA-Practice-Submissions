/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Method 2 [Optimised] O(n), O(h) // will not work if either p or q is not present
        if(root==null) return null;
        if(root.val==p.val || root.val==q.val) return root;
        TreeNode l = lowestCommonAncestor(root.left, p, q);
        TreeNode r = lowestCommonAncestor(root.right, p, q);
        if(l!=null && r!=null) return root;
        if(l!=null) return l;
        else return r;
    }
}