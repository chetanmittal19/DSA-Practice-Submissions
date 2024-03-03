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

        // Method 2 [Iterative] O(n), O(logn)
        // List<Integer> res = new ArrayList<Integer>();
        // Stack<TreeNode> st = new Stack<>();
        // TreeNode current = root;
        // while(current!=null || !st.isEmpty()) {
        //     while(current!=null) {
        //         st.push(current);
        //         current = current.left;
        //     }
        //     current = st.pop();
        //     res.add(current.val);
        //     current = current.right;
        // }
        // return res;  

        // Method 3 [Morris Traversal] O(2n), O(1)
        List<Integer> res = new ArrayList<>();
        TreeNode curr = root;
        while(curr!=null) {
            if(curr.left==null) {
                res.add(curr.val);
                curr = curr.right;
            } else {
                TreeNode pred = findPredecessor(curr);
                if(pred.right==null) {
                    pred.right = curr;
                    curr = curr.left;
                } else {
                    res.add(curr.val);
                    pred.right=null;
                    curr = curr.right;
                }
            }
        }
        return res;
    }

    private TreeNode findPredecessor(TreeNode curr) {
        TreeNode t = curr.left;
        while(t.right!=null && t.right!=curr) t = t.right;
        return t;
    }

    // private void inorder(TreeNode root, List<Integer> res){
    //     if(root==null) return;
    //     inorder(root.left, res);
    //     res.add(root.val);
    //     inorder(root.right, res);
    // }
}