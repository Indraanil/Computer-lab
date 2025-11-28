#include <iostream>
using namespace std;
bool isfull(int &rear , int size){
    return rear == size-1;
}
bool isempty(int &front,int &rear){
    return front == -1 && rear == -1;
}
void enqueue(int n,int size  , int &front ,int &rear , int arr[]){
    if(isfull(rear , size)){
        cout << "Queue is full " << endl;
     }else{
    if(front == -1 && rear ==-1){
        front = rear = 0;
    }
    arr[rear] = n;
    rear++;
}
} 
void dequeue(int arr[] , int &front  , int &rear){
    if(isempty(front , rear)){
        cout << "Empty nothing to delete " << endl;
    }
    if(front==rear){
        cout << arr[front] << endl;
        front  = rear  = -1;
    }else{
        cout <<  arr[front] << endl;
        front++;
    }
}
void display(int front , int rear , int arr[]){
    if(isempty(front , rear)){
        cout << "empty nothing to display" << endl;
    }else{
        for(int i =front ;i <rear ;i++){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
struct Node{
    int data;
    Node* next;
    
};
Node* enqueueL(Node* &front,Node* &rear ,int n){
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    if(front == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    
}
void dequeuel(Node* &front , Node* &rear){
    if(front==rear){
        cout << front->data << " ";
        delete front;
        front = rear = NULL;
    }else{
        Node* temp = front;
        front = front->next;
       cout << temp->data << endl;

       delete temp;
    }
}
void displayL(Node* front ,Node*rear , int size){
    Node* temp = front;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    // int front=-1 ,rear =-1;
    // int arr[100 ];
    // enqueue(10 , 8 ,front , rear , arr);
    // enqueue(20 , 8 ,front , rear , arr);
    // enqueue(30 , 8 ,front , rear , arr);
    // display(front , rear , arr);
    // dequeue(arr , front , rear);
    // display(front , rear , arr);

    Node* front =NULL;
    Node* rear = NULL;
    enqueueL(front , rear , 2);
    enqueueL(front , rear , 5);
    enqueueL(front , rear , 8);

    displayL(front , rear , 5);

    dequeuel(front , rear);
    dequeuel(front , rear);
    dequeuel(front , rear);



}