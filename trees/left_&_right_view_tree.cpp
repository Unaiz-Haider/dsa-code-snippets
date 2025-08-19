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
/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    void leftView(vector<int> &ans, Node* root, int &maxLevel, int level){
        if(!root) return;
        if(level == 0) ans.push_back(root->data);
        if(level > maxLevel){
            ans.push_back(root->data);
            maxLevel = level;
        }
        leftView(ans, root->left, maxLevel, level + 1);
        leftView(ans, root->right, maxLevel, level + 1);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        int maxLevel = 0;
        leftView(ans, root, maxLevel, 0);
        return ans;
    }
};



class Solution {
public:
    void rightView(vector<int> &ans, TreeNode* root, int &maxLevel, int level){
        if(!root) return;
        if(level == 0) ans.push_back(root->val);
        if(level > maxLevel){
            ans.push_back(root->val);
            maxLevel = level;
        }
        rightView(ans, root->right, maxLevel, level + 1);
        rightView(ans, root->left, maxLevel, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxLevel = 0;
        rightView(ans, root, maxLevel, 0);
        return ans;
        
    }
};