/*
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root, val);
        return root;
    }
    
    void helper(TreeNode *node, int val){
        /* Will not ever add an existing val to the tree */
        if(val > node->val){
            if(node->right){
                helper(node->right, val);
            } else {
                TreeNode *create = new TreeNode(val);
                node->right = create;
            }
        } else {
            if(node->left){
                helper(node->left, val);
            } else {
                TreeNode *create = new TreeNode(val);
                node->left = create;
            }
        }
    }
};