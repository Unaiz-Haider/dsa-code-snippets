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

 
 //Doing every time height check ~ O(n^2)
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};



//Doing height check difference from bottom
class Solution {
public:
    int check(TreeNode* root){
        if(!root) return 0;

        int leftHeight = check(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = check(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};