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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // write your code here
        if(!root) return NULL;
        if(root->val == key) return helper(root);

        TreeNode *curr = root;
        while(curr) {
            if(curr->val > key) {
                if(curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                } else curr = curr->left;
            } else {
                if(curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                } else curr = curr->right;
            }
        }
        return root;
    }

    TreeNode* helper(TreeNode* root) {
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        while(root->right) root=root->right;
        return root;
    }
};