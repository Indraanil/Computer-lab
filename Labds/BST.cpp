#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right =NULL;
    }   
};
Node* insert(Node* root ,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(root->data < val){
        root->right = insert(root->right ,val);
    }else{
        root->left = insert(root->left , val);
    }
    return root;
}
bool search(Node* root , int element){
    if(root==NULL){
        return false;
    }
    if(element == root->data){
        return true;
    }
    if(element < root->data){
      return   search(root->left ,element);
    }else{
      return   search(root->right ,element);
    }
}
Node* minvalRight(Node * root){
    Node* current = root;
    while(current && current->left!=NULL){
        current = current->left;
    }
    return current;
}
Node* deleteNode(Node* root , int key){
    if(root == NULL){
        return root;
    }
    
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key >root->data){
        root->right = deleteNode(root->right ,key);
    }else{
    
    if(root->right==NULL){
        Node* temp = root->left;
        delete root;
        return temp;
    }else if(root->left==NULL){
        Node* temp = root->right;
        delete root;
        return temp;
    }
    
    Node* temp = minvalRight(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right , temp->data);
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
int main(){
    Node* root = NULL;
    root = insert(root ,20);
    root =insert(root ,40);
    root =insert(root ,50);
    root =insert(root ,10);
    root =insert(root ,12);

    preorder(root);

    if(search(root ,0)){
        cout << "Found" ;
    }else{
        cout << "Not found";
    }

}