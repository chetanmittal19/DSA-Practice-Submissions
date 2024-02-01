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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        // Method 1 [Stack, Queue]
        // if(root==null) return new ArrayList<>();
        // Queue<TreeNode> q = new LinkedList<>();
        // Stack<TreeNode> st = new Stack<>();
        // List<List<Integer>> res = new LinkedList<>();
        // q.offer(root);
        // boolean rev = false;

        // while(!q.isEmpty()){
        //     List<Integer> l = new LinkedList<>();
        //     int s = q.size();
        //     for(int i=0; i<s; i++){
        //         TreeNode front = q.remove();
        //         if(rev) st.push(front);
        //         else l.add(front.val);

        //         if(front.left!=null) q.offer(front.left);
        //         if(front.right!=null) q.offer(front.right);
        //     }

        //     if(rev) while(!st.isEmpty()) l.add(st.pop().val);
        //     res.add(l);
        //     rev=!rev;
        // }
        // return res;

        // Method 2 [Double Stack]
        if(root==null) return new ArrayList<>();

        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        List<List<Integer>> res = new LinkedList<>();

        s1.push(root);
        while(!s1.isEmpty()) {
            LinkedList<Integer> l = new LinkedList<>();
            while(!s1.isEmpty()) {
                TreeNode top = s1.pop();
                l.add(top.val);
                if(top.left!=null) s2.push(top.left);
                if(top.right!=null) s2.push(top.right);
                
            }
            res.add(l);
            LinkedList<Integer> m = new LinkedList<>();
            while(!s2.isEmpty()) {
                TreeNode top = s2.pop();
                m.add(top.val);
                if(top.right!=null) s1.push(top.right);
                if(top.left!=null) s1.push(top.left);
            }
            if(m.size()>0) res.add(m);
        }
        return res;
    }
}