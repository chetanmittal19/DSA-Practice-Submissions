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
    public boolean findTarget(TreeNode root, int k) {
        // Method 1 [ArrayList, 2 pointer] O(2n), O(n)
        // using inorder traversal store all elements in list, so it will be sorted. Then apply 2 pointer

        // Method 2 [HashMap] O(n), O(n)
        return isPair(root, k, new HashSet<Integer>());
    }

    private boolean isPair(TreeNode root, int k, HashSet<Integer> s) {
        if(root==null) return false;
        if(isPair(root.left, k, s)) return true;
        if(s.contains(k-root.val)) return true;
        else s.add(root.val);
        return isPair(root.right, k, s);
    }
}