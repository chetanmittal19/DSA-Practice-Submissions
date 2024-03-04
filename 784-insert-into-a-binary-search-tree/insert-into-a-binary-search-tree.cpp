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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Method 1 [Recursion] O(h), O(h)
        // if(root==NULL) return new TreeNode(val);
        // if(root->val > val) root->left = insertIntoBST(root->left, val);
        // else root->right = insertIntoBST(root->right, val);
        // return root;

        // Method 2 [Iterative] O(h), O(1)
        TreeNode *newNode = new TreeNode(val);
        TreeNode *prev = NULL, *curr = root;
        while(curr) {
            prev = curr;
            if(curr->val > val) curr = curr->left;
            else curr = curr->right;
        }
        if(prev==NULL) return newNode;
        if(prev->val > val) prev->left = newNode;
        else prev->right = newNode;
        return root;
    }
};