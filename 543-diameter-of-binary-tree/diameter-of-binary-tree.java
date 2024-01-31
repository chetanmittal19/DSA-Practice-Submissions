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
    int res = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        // Method 1 [BruteForce] O(N^2), O(N)
        // if(root==null) return 0;
        // int d1 = height(root.left) + height(root.right);
        // int d2 = diameterOfBinaryTree(root.left);
        // int d3 = diameterOfBinaryTree(root.right);
        // return Math.max(d1, Math.max(d1, d2));

        // Method 2 [Better, HashMap] Precompute and store height of each node in hashmap
        // O(N), O(N)

        // Method 3 [Optimised] O(n), O(n)
        calculateDiameter(root);
        return res;
    }

    private int calculateDiameter(TreeNode root) {
        if(root==null) return 0;
        int l = calculateDiameter(root.left);
        int r = calculateDiameter(root.right);
        res = Math.max(res, l + r);
        return 1 + Math.max(l, r);
    }

    // private int height(TreeNode root) {
    //     if(root==null) return 0;
    //     int lh = height(root.left);
    //     int rh = height(root.right);
    //     return 1 + Math.max(lh, rh);
    // }
}