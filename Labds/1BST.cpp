#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *BST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (root->data < val)
    {
        root->right = BST(root->right, val);
    }
    else if (root->data > val)
    {
        root->left = BST(root->left, val);
    }
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        cout << curr->data << " ";

        if (curr->right != NULL)
        {
            st.push(curr->right);
        }
        if (curr->left != NULL)
        {
            st.push(curr->left);
        }
    }
}

void inorder(Node *root)
{
    Node *curr = root;
    stack<Node *> st;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}
void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void Inorderr(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorderr(root->left);
    cout << root->data << " ";
    Inorderr(root->right);
}
void Postorderr(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorderr(root->left);
    Postorderr(root->right);
    cout << root->data << " ";
}
bool SearchinBST(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    if (root->data < val)
    {
        SearchinBST(root->right, val);
    }
    else if (root->data > val)
    {
        SearchinBST(root->left, val);
    }
}
Node *minval(Node *root)
{
    Node *curr = root;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {

        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        Node *temp = minval(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
    cout << endl;
}
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return (left + right + 1);
}
int main()
{
    Node *root = NULL;

    while (true)
    {
        cout << "BST operation" << endl;
        cout << "1.Insert in BST \n 2.Search in BST \n 3.Delete Node in BST \n 4.Count node in BST \n 5.height of bst \n 6 to display with recursion preorder \n7.To display withoout recursiion preorder \n8.Existing program";
        cout << "Enter your choice " << endl;
        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "You are inserting node in BST" << endl;
            cout << "How many node you want to insert" << endl;
            int size;
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                int val;
                cout << "Enter the value" << endl;
                cin >> val;
                root = BST(root, val);
            }
            break;

        case 2:
            cout << "You are searching in BST" << endl;
            int value;
            cout << "Enter the value to serach" << endl;
            cin >> value;
            if (SearchinBST(root, value))
            {
                cout << "found" << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
            break;

        case 3:
            cout << "you are deleting node from bst " << endl;
            cout << "ENter the value to deltet" << endl;
            int vale;
            cin >> vale;
            root = deleteNode(root, vale);
            break;

        case 4:

            cout << "counting node in bst" << countNodes(root) << endl;
            break;

        case 5:
            cout << "Height of bst" << height(root) << endl;

            break;

        case 6:
            cout << "To displaty tree with recursion " << endl;
            preorder(root);
            cout << endl;
            break;

        case 7:
            cout << "To display tree without recursion" << endl;
            Preorder(root);
            cout << endl;
            break;

        case 8:
            cout << "You are Existing Program" << endl;
            exit(0);

        default:
            cout << "Invalid choice \n";
        }
    }
}