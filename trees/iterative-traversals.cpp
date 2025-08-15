#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};


void inorderTraversal(Node* root){
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}

void preOrderTraversal(Node* root){
    //iterative solution
    if(root == nullptr) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout << root->data << " ";
        if(root->right != NULL)
            st.push(root->right);
        if(root->left != NULL)
            st.push(root->left);
    }
    return;
}

void postOrderTraversal(Node* root){
   if (root == NULL) return;

    stack<Node*> st;
    Node* lastVisited = NULL;

    while (!st.empty() || root != NULL) {
        if (root != NULL) {
            st.push(root);
            root = root->left;  // go left as far as possible
        } 
        else {
            Node* peekNode = st.top();
            // if right child exists and not visited yet, go right
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                root = peekNode->right;
            } 
            else {
                cout << peekNode->data << " "; // visit node
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;
    
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout<<endl;
    
    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout<<endl;
    

    return 0;
}
