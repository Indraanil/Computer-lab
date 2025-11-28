#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
};
Node* buildtree(Node*root ,int value){
    if(root==NULL){
        root = new Node();
        root->data = value;
        root->left =root->right =NULL;
        return root;
    }
    if(value < root->data){
        root->left = buildtree(root->left , value);
    }else{
        root->right = buildtree(root->right , value);
    }
    return root;
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inoorder(Node* root){
    if(root ==NULL){
        return;
    }
    inoorder(root->left);
    cout <<root->data << " ";
    inoorder(root->right);

}
int main(){
    Node* root =NULL;
    root =buildtree(root ,10);
    root=buildtree(root ,20);
    root=buildtree(root ,30);
    root=buildtree(root ,0);
    root=buildtree(root ,3);
    root=buildtree(root ,4);

    preorder(root);
}