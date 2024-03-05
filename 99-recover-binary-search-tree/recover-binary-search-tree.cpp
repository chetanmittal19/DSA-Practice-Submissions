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
    void recoverTree(TreeNode* root) {
        // Method 1 [ArrayList] O(2n), O(n)
        // if(!root) return;
        // vector<TreeNode*> v;
        // getSortedElements(root, v);
        // TreeNode *prev = new TreeNode(INT_MIN);
        // TreeNode *first = NULL, *second = NULL;
        // for(int i=0; i<v.size(); i++) {
        //     if(v[i]->val < prev->val) {
        //         if(!first) first = prev;
        //         second = v[i];
        //     }
        //     prev = v[i];
        // }
        // if(!first) return; // if tree is sorted, then first is always null
        // int temp = first->val;
        // first->val = second->val;
        // second->val = temp;

        // Method 2 [Recursion]

        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        fixSwapped(root, prev, first, second);
        if(!first) return;
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

    void fixSwapped(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
        if(!root) return;
        fixSwapped(root->left, prev, first, second);
        if(prev && root->val < prev->val) {
            if(!first) first = prev;
            second = root;
        }
        prev = root;
        fixSwapped(root->right, prev, first, second);
    }

    // void getSortedElements(TreeNode *root, vector<TreeNode*> &v) {
    //     if(!root) return;
    //     getSortedElements(root->left, v);
    //     v.push_back(root);
    //     getSortedElements(root->right, v);
    // }
};