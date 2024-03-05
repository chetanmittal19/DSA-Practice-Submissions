/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Method 1 [Recursion] O(h), O(h)
        // if(!root) return NULL;
        // int curr = root->val;
        // if(curr < p->val && curr < q->val) return lowestCommonAncestor(root->right, p, q);
        // if(curr > p->val && curr > q->val) return lowestCommonAncestor(root->left, p, q);
        // return root;

        // Method 2 [Iterative] O(h), O(1)
        TreeNode *curr = root;
        while(curr) {
            int x = curr->val;
            if(x < p->val && x < q->val) curr = curr->right;
            else if(x > p->val && x > q->val) curr = curr->left;
            else return curr;
        }
        return NULL;
    }
};