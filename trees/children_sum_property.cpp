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
    bool findValue(Node* root){
        if(!root || !root->left && !root->right) return 1;
        
        int leftData = (root->left ? root->left->data : 0);
        int rightData = (root->right ? root->right->data : 0);
        
        if(root->data == leftData + rightData
            && findValue(root->left)
            && findValue(root->right)){
                return 1;
            }
            return false;
    }
    int isSumProperty(Node *root) {
        // code here
        return findValue(root);
    }
};