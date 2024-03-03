/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        HashMap<TreeNode, TreeNode> parentTrack = new HashMap<>();
        markParents(root, parentTrack); // Mark parents of all nodes
        HashMap<TreeNode, Boolean> visited = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        visited.put(target, true);
        queue.add(target);
        int currLevel = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            if(currLevel++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode current = queue.poll();
                if (current.left != null && !visited.containsKey(current.left)) {
                    queue.add(current.left);
                    visited.put(current.left, true);
                }

                if (current.right != null && !visited.containsKey(current.right)) {
                    queue.add(current.right);
                    visited.put(current.right, true);
                }

                if (parentTrack.containsKey(current) && !visited.containsKey(parentTrack.get(current))) {
                    queue.add(parentTrack.get(current));
                    visited.put(parentTrack.get(current), true);
                }
            }
        }

        // Stores nodes at distance k from the target
        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            result.add(current.val);
        }
        return result;
    }

    private void markParents(TreeNode root, HashMap<TreeNode, TreeNode> parentTrack) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            if (current.left != null) {
                parentTrack.put(current.left, current);
                queue.add(current.left);
            }

            if (current.right != null) {
                parentTrack.put(current.right, current);
                queue.add(current.right);
            }
        }
    }
}