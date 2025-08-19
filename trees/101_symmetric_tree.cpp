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
    bool checkMirror(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
       return checkMirror(left->left, right->right) && checkMirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root;
        TreeNode* right = root;
        return checkMirror(left, right);
        
    }
};