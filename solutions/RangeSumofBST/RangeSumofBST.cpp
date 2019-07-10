/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        
        /* Calling recursively first */
        if(root->left != NULL){
            sum += rangeSumBST(root->left, L, R);
        }
        
        if(root->right != NULL){
            sum += rangeSumBST(root->right, L, R);
        }
        
        /* Now adding current node's val */
        if(root->val >= L && root->val <= R){
            sum += root->val;
        }
        
        return sum;
    }
};