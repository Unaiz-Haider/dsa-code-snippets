/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        
        if(!root) return ans;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        map<int, int> mp;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int line = temp.second;
            
            if(mp.find(line) == mp.end()) mp[line] = node->data;
            
            if(node->left){
                q.push({node->left, line - 1});
            }
            if(node->right){
                q.push({node->right, line + 1});
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};