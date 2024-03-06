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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Method 1 [BruteForce] O(n*h), O(h) -> recursion
        // if(preorder.size()==0) return NULL;
        // TreeNode *root = new TreeNode(preorder[0]);
        // for(int i=1; i<preorder.size(); i++) {
        //     insert(root, preorder[i]);
        // }
        // return root;

        // Method 2 [Optimised] O(n + nlogn + n), O(n)
        // copy all elements into another array and sort that array.
        // now we have both inorder and preorder traversal, so we can create BST in O(n)

        // Method 3 
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

    TreeNode *build(vector<int>& preorder, int &i, int bound) {
        if(i==preorder.size() || preorder[i]>bound) return NULL;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }

    // TreeNode* insert(TreeNode *root, int x) {
    //     if(root==NULL) return new TreeNode(x);
    //     if(root->val > x) root->left = insert(root->left, x);
    //     else root->right = insert(root->right, x);
    //     return root;
    // }
};