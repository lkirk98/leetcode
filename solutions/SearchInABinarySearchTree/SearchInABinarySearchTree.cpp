/*
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. 
Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
*/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val)
            return root;
        else if (root->left && root->val > val)
            return searchBST(root->left, val);
        else if (root->right && root->val < val)
            return searchBST(root->right, val);
            
        return NULL;
    }
};