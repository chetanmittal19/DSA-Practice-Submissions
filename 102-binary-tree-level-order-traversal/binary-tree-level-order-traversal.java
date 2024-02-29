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
    public List<List<Integer>> levelOrder(TreeNode root) {
        // Method 1 
        if(root==null) return new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> t = new ArrayList<>();
        q.add(root);
        q.add(null);
        while(q.size()>1) {
            TreeNode front = q.poll();
            if(front==null) {
                res.add(t);
                t = new ArrayList<>();
                q.add(null);
                continue;
            }
            t.add(front.val);
            if(front.left!=null) q.add(front.left);
            if(front.right!=null) q.add(front.right);
        }
        res.add(t);
        return res;


        // Method 1 [Queue] O(n), O(n)
        // if(root==null) return new ArrayList<>();
        // List<List<Integer>> res = new ArrayList<>();
        // Queue<TreeNode> q = new LinkedList<>();
        // q.offer(root);
        // while(!q.isEmpty()) {
        //     int s = q.size();
        //     List<Integer> l = new ArrayList<>();
        //     for(int i=0; i<s; i++) {
        //         TreeNode front = q.remove();
        //         l.add(front.val);
        //         if(front.left!=null) q.offer(front.left);
        //         if(front.right!=null) q.offer(front.right);
        //     }
        //     res.add(l);
        // }
        // return res;
    }
}