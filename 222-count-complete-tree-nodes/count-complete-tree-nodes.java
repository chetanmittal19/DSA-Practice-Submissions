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
    public int countNodes(TreeNode root) {
        // Method 1 [BruteForce] O(n), O(h)
        // if(root==null) return 0;
        // return 1 + countNodes(root.left) + countNodes(root.right);

        // Method 2 [Optimised]
        if(root==null) return 0;
        int lh = 0, rh = 0;
        TreeNode l = root, r = root;
        while(l!=null) {
            lh++;
            l=l.left;
        }

        while(r!=null) {
            rh++;
            r=r.right;
        }

        if(lh==rh) return (int)Math.pow(2,lh)-1;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}