// #include <iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node* previous;
    
// };
// void circularDoubly(Node*&head ,Node*&rear , int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = NULL;
//     newNode->next = NULL;


//     if(head==NULL){
//         head = rear = newNode;
//         head->next = head;
//         head->previous = head;
//         return;
//     }
//     newNode->previous = rear;
//     newNode->next = head;
//     rear->next = newNode;
//     head->previous = newNode;
//     rear = newNode;
// }
// void deleteCircularDoubly(Node*&head , Node*&rear){
//     if(head == rear){
//         Node* temp = rear;
//         cout << temp->data << " ";
//         delete temp;
//         head=rear =NULL;
//         return;
//     }
//     Node* temp = rear;
//     cout << temp->data << endl;
//     rear = rear->previous;
//     rear->next = head;
//     head->previous = rear;
//     delete temp;

// }
// void display(Node* head ,Node*rear){
//     Node* temp = head;
//     do{
//         cout << temp->data << " ";
//         temp = temp->next;
//     }while(temp!=head);
//     cout << endl;
// }
// int main(){
//     Node* head = NULL;
//     Node* rear = NULL;
//     circularDoubly(head  , rear ,90);
//     circularDoubly(head  , rear ,50);
//     circularDoubly(head  , rear ,30);
//     circularDoubly(head  , rear ,10);

//     display(head ,rear);
//     deleteCircularDoubly(head ,rear);
//     deleteCircularDoubly(head ,rear);
//     deleteCircularDoubly(head ,rear);

//     display(head ,rear);
//     circularDoubly(head  , rear ,30);
//     display(head ,rear);

    
// }



#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*  next ;
    Node* previous;
    Node(int val){
        data = val;
        next = previous = NULL;
    }
};
void doublylist(Node* &head , Node* &rear ,int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = rear = newNode;
    }else{
        rear->next = newNode;
        newNode->previous = rear;
        rear = newNode;
    }
}
void circulardoubly(Node*&head , Node*&rear , int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = rear = newNode;
        newNode->next = newNode;
        newNode->previous = newNode;
    }else{
        newNode->previous = rear;
        newNode->next = head;
        rear->next = newNode;
        head->previous = newNode;

        rear =  newNode;
    }
}
void deleteFrontCircular(Node*&head , Node*&rear){
    if(head==rear){
        cout << head->data << " ";
        delete head;
        head = rear = NULL;
        return;
    }else{
        Node* curr = head;
        head = head->next;
        head->previous = rear;
        rear->next = head;
        cout << curr->data << endl;
        delete curr;

    }
}
void deleteBackCircular(Node* &head , Node*&rear){
    if(head == rear){
        cout << rear->data << endl;
        delete rear;
        head = rear = NULL;
        return;
    }
    Node* curr = rear;
    rear  = rear->previous;
    rear->next = head;
    head->previous = rear;
    cout << curr->data <<  endl;
    delete curr;
}
void display(Node*&head , Node*&rear){
    Node* curr = head;
    do{
        if(curr->data%2 == 0){
            cout << curr->data << " ";
        }
        curr = curr->next;
    }while(curr!=head);
}
void swapNodes(Node*&head , Node* &rear){
    if(head == NULL || head == rear){
        return;
    }
    int curr = head->data;
    head->data = rear->data;
     rear->data= curr ;

}
int main(){
    Node* head = NULL;
    Node* rear = NULL;

    // doublylist(head , rear , 10);
    // doublylist(head , rear , 20);
    // doublylist(head , rear , 30);
    // doublylist(head , rear , 40);

    // display(head , rear);

    circulardoubly(head , rear , 55);
    circulardoubly(head , rear , 60);
    circulardoubly(head , rear , 70);
    circulardoubly(head , rear , 80);

//     display(head ,rear); 
// cout << endl;
//     deleteFrontCircular(head , rear);
//     display(head ,rear); 
// cout << endl;
//     deleteBackCircular(head , rear);
    swapNodes(head ,rear);
    display(head ,rear); 

}