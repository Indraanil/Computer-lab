// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *left;
//     Node *right;
//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//         left = right = NULL;
//     }
// };

// int heightBalanced(Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int left = heightBalanced(root->left);
//     int right = heightBalanced(root->right);

//     return max(left, right) + 1;
// }
// int getbalanced(Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return heightBalanced(root->left) - heightBalanced(root->right);
// }

// // left subtree
// Node *rightrotate(Node *x)
// {
//     Node *y = x->left;
//     Node *dull = y->right;
//     y->right = x;
//     x->left = dull;
//     return y;
// }

// // right subtree
// Node *leftrotate(Node *y)
// {
//     Node *x = y->right;
//     Node *dull = x->left;
//     x->left = y;
//     y->right = dull;
//     return x;
// }

// Node *insert(Node *root, int val)
// {
//     if (root == NULL)
//     {
//         return new Node(val);
//     }
//     if (root->data < val)
//     {
//         root->right = insert(root->right, val);
//     }
//     else if (root->data > val)
//     {
//         root->left = insert(root->left, val);
//     }
//     else
//     {
//         return root;
//     }

//     int balance = getbalanced(root);

//     // LL
//     if (balance > 1 && val < root->left->data)
//     {
//         return rightrotate(root);
//     }

//     // RR
//     if (balance < -1 && val > root->right->data)
//     {
//         return leftrotate(root);
//     }

//     // LR
//     if (balance > 1 && val > root->left->data)
//     {
//         root->left = leftrotate(root->left);
//         return rightrotate(root);
//     }

//     // RL
//     if (balance < -1 && val < root->right->data)
//     {
//         root->right = rightrotate(root->right);
//         return leftrotate(root);
//     }

//     return root;
// }

// void preorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     preorder(root->left);
//     cout << root->data << " ";
//     preorder(root->right);
// }
// int main()
// {
//     Node *root = NULL;
//     root = insert(root, 50);
//     root = insert(root, 30);
//     root = insert(root, 10);
//     root = insert(root, 70);
//     root = insert(root, 80);
//     root = insert(root, 90);

//     preorder(root);
// }



#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right =NULL;
    }
};

int balances(Node* root){
    if(root == NULL ){
        return 0;

    }
    int left = balances(root->left);
    int right = balances(root->right);
    return max(left , right)+1;
}
int heightleftright(Node* root){
    if(root == NULL){
        return 0;
    }
    return balances(root->left) - balances(root->right);
}
Node* leftsubtree(Node* x){
    Node* y = x->left;
    Node* temp = y->right;
    y->right = x;
    x->left = temp;
    return y;
}
Node* rightsubtree(Node* y){
    Node* x = y->right;
    Node* temp = x->left;
    x->left = y;
    y->right = temp;
    return x;
}
Node* insert(Node* root , int val){
    if(root == NULL){
        return new Node(val);
    }
    if(root->data < val){
        root->right =  insert(root->right , val);
    }else if (root->data > val){
        root->left = insert(root->left , val);
    }else{
        return root;
    }

    int balcd = heightleftright(root);

    if(balcd > 1 &&  val < root->left->data){
       return leftsubtree(root);
    }
    if(balcd < -1 && val > root->right->data){
       return rightsubtree(root);
    }

    if(balcd > 1 && val > root->left->data){
        root->left = rightsubtree(root->left);
        return leftsubtree(root);
    }
    if(balcd < -1 && val < root->right->data){
        root->right = leftsubtree(root->right);
        return rightsubtree(root);
    }
    return root;

}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();

        cout <<  curr->data << " ";
        if(curr->left!=NULL){
            st.push(curr->left);
        }  
        if( curr->right!=NULL){
            st.push(root->right);
        }
    }
}
void inorder(Node* root){
    stack<Node*> st;
    Node* curr = root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr  = st.top();
        st.pop();
        cout << curr->data << " ";
        curr  = curr->right;


    }
}
int main(){
    Node* root = NULL;

    root = insert(root ,19);
     root =insert(root ,9);
     root =insert(root ,29);
     root =insert(root ,9);
     root =insert(root ,10);
     root =insert(root ,11);

    preorder(root);
    cout << endl;
    inorder(root);
}