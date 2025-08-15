#include <iostream>
#include <queue>
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
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(root == nullptr) return;
    
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == nullptr) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
    
}

//BFS
void levelOrderTraversal(Node* root){
    if(root == nullptr) return;
    
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       Node* current = q.front();
       q.pop();
       
       cout << current->data << " ";
       
       if(current->left) q.push(current->left);
       if(current->right) q.push(current->right);
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
    
    //BFS
    cout << "Level-order traversal: ";
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}
