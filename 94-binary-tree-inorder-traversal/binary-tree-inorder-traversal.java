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
    public List<Integer> inorderTraversal(TreeNode root) {
        // Method 1 [Recursive] O(n), O(n)
        // if(root==null) return new ArrayList<Integer>();
        // List<Integer> res = new ArrayList<Integer>();
        // inorder(root, res);
        // return res;

        // Method 2 [Iterative] O(n), O(n)
        List<Integer> res = new ArrayList<Integer>();
        Stack<TreeNode> st = new Stack<>();
        TreeNode current = root;

        while(current!=null || !st.isEmpty()) {
            while(current!=null) {
                st.push(current);
                current = current.left;
            }
            current = st.pop();
            res.add(current.val);
            current = current.right;
        }
        return res;  
    }

    // private void inorder(TreeNode root, List<Integer> res){
    //     if(root==null) return;
    //     inorder(root.left, res);
    //     res.add(root.val);
    //     inorder(root.right, res);
    // }
}