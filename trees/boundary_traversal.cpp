/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void leftBoundary(vector<int> &ans, Node* root){
        Node* temp = root->left;
        while(temp != nullptr){
            if(!(temp->left == nullptr && temp->right == nullptr)) 
                ans.push_back(temp->data);
            if(temp->left){
                temp = temp->left;
            }
            else temp = temp->right;
        }
    }
    void rightBoundary(vector<int> &ans, Node* root){
        Node* temp = root->right;
        vector<int> tmp;
        while(temp != nullptr){
            if(!(temp->left == nullptr && temp->right == nullptr))
                tmp.push_back(temp->data);
            if(temp->right){
                temp = temp->right;
            }
            else temp = temp->left;
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
            ans.push_back(tmp[i]);
    }
    void leafNodes(vector<int> &ans, Node* root){
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->data);
            return;
        }
        leafNodes(ans, root->left);
        leafNodes(ans, root->right);
    }
    vector<int> boundaryTraversal(Node *root) {
        // LEFT -> LEAF -> RIGHT
        vector<int> ans;
        
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->data);
            return ans;
        }
        if (!root) return ans;
        ans.push_back(root->data);
        
        leftBoundary(ans, root);
        leafNodes(ans, root);
        rightBoundary(ans, root);
        
        return ans;
    }
};