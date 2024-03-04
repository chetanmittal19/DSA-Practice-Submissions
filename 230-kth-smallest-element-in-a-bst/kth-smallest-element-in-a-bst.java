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
    public int kthSmallest(TreeNode root, int k) {
        // Method 3 [Morris Inorder Traversal] O(2n), O(1)
        int count = 0;
        int kthSmallestValue = Integer.MIN_VALUE;
        TreeNode current = root;

        while (current != null) {
            if (current.left == null) {
                count++;
                if (count == k) {
                    kthSmallestValue = current.val;
                    break;
                }
                current = current.right;
            } else {
                TreeNode predecessor = findPredecessor(current);
                if (predecessor.right == null) {
                    predecessor.right = current;
                    current = current.left;
                } else {
                    predecessor.right = null;
                    count++;
                    if (count == k) {
                        kthSmallestValue = current.val;
                        break;
                    }
                    current = current.right;
                }
            }
        }
        return kthSmallestValue;
    }

    private TreeNode findPredecessor(TreeNode node) {
        TreeNode predecessor = node.left;
        while (predecessor.right != null && predecessor.right != node) {
            predecessor = predecessor.right;
        }
        return predecessor;
    }
}