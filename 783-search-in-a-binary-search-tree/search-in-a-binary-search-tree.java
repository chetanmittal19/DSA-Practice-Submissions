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
    public TreeNode searchBST(TreeNode root, int val) {
        // Method 1 [Recursion] O(h), O(h)
        // if(root==null) return null;
        // if(root.val == val) return root;
        // else if(root.val>val) return searchBST(root.left, val);
        // else return searchBST(root.right, val);

        // Method 2 [Iterative] O(h), O(1)
        TreeNode curr = root;
        while(curr!=null) {
            if(curr.val == val) return curr;
            else if(curr.val>val) curr = curr.left;
            else curr = curr.right;
        }
        return null;
    }
}