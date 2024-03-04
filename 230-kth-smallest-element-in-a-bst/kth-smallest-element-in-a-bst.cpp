/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // Method 1 [BruteForce] O(n + nlogn), O(n)
        // store all nodes values into list and sort list to find given element

        // Method 2 [Inorder Traversal] O(n), O(n)
        int ans = 0, count = 0;
        findKthSmallest(root, k, ans, count);
        return ans;
    }

    void findKthSmallest(TreeNode *root, int k, int &ans, int &count) {
        if(!root) return;
        findKthSmallest(root->left, k, ans, count);
        count++;
        if(count==k) ans = root->val;
        if(count<k) findKthSmallest(root->right, k, ans, count);
    }
};