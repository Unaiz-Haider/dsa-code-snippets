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
    void findPaths(TreeNode* root, vector<string> &ans, string temp){
        if(!root){
            return;
        }

        if(!temp.empty()){
            temp += "->";
        }
        temp += to_string(root->val);

        if(!root->left && !root->right) ans.push_back(temp); 

        findPaths(root->left, ans, temp);
        findPaths(root->right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp;
        if(!root) return ans;
        findPaths(root, ans, temp);
        return ans;
    }
};