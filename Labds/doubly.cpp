#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* previous;
};
void insert(Node*&head , Node*&rear ,int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = rear = newNode;
    }
    rear->next = newNode;
    newNode->previous  =rear;
    rear = newNode;
}
void evenNodes(Node*&head){
    Node* temp = head;
    while(temp!=NULL ){
        if(temp->data  % 2==0){
            cout << temp->data << " ";
            temp = temp->next;
        }else{
            temp = temp->next;
            continue;
        }
    }
    cout << endl;
}
void swap(Node* &head, Node*&rear){
    swap(head->data , rear->data);
}
int main(){
    Node* head = NULL;
    Node* rear = NULL;

    // insert(head ,rear ,20);
    // insert(head ,rear ,90);
    // insert(head ,rear ,60);
    // insert(head ,rear ,55);
    // insert(head ,rear ,30);


    // evenNodes(head);
    // swap(head ,rear);
    // evenNodes(head);

    int option;
    int element;
    do {
    cout << "--Which operation you want to perform" << endl;
    cout << " 1.insert \n 2.even nodes \n 3. swap" << endl;
   
    cin >> option;
    switch(option){
        case 1:
        cout << "Enter elements" << endl;
        while(element!=-1){
            cin >> element;
            insert(head , rear , element);
        }
        case 2:
        evenNodes(head);
        case 3:
        swap(head ,rear);
    }
    }while(option!=3);

}