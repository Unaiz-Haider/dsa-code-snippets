//Using path finding with extra space
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;

        path.push_back(root);  // add current node

        if (root == target) return true;

        // search left or right
        if (findPath(root->left, target, path) || findPath(root->right, target, path))
            return true;

        path.pop_back();  // backtrack
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        // find both paths
        findPath(root, p, path1);
        findPath(root, q, path2);

        // compare paths
        TreeNode* ans = nullptr;
        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            ans = path1[i];
            i++;
        }
        return ans;
    }
};

//Using recursion without extra space with returned value
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left) return right;
        else if(!right) return left;
        return root;
    }
};
