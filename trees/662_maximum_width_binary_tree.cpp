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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while(!q.empty()){
            int levelSize = q.size();
            long long firstIndex = q.front().second;
            long long lastIndex = q.back().second;
            maxWidth = max(maxWidth, (int)(lastIndex - firstIndex + 1));
            for(int i = 0; i < levelSize; i++){
                TreeNode*node = q.front().first;
                long long index = q.front().second - firstIndex;
                q.pop();
                if(node->left)q.push({node->left, 2 * index});
                if(node->right)q.push({node->right, 2 * index + 1});
            }
        }
        return maxWidth;
    }
};