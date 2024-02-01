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
    public List<Integer> rightSideView(TreeNode root) {
        // Method 1 [Queue]
        if(root==null) return new LinkedList<>();
        List<Integer> res = new LinkedList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode front = q.poll();
                if(i==n-1) res.add(front.val);
                if(front.left!=null) q.add(front.left); 
                if(front.right!=null) q.add(front.right); 
            }
        }
        return res;

        // Method 2 [Better] O(n), O(n)
        // if(root==null) return new LinkedList<>();
        // List<Integer> res = new LinkedList<>();
        // rightSideView(root, res, 1);
        // return res;   
    }

    // int m = 0;
    // private void rightSideView(TreeNode root, List<Integer> res, int maxValue){
    //     if(root==null) return;
    //     if(m < maxValue){
    //         m++;
    //         res.add(root.val);
    //     }
    //     rightSideView(root.right, res, maxValue+1);
    //     rightSideView(root.left, res, maxValue+1);
    // }
}