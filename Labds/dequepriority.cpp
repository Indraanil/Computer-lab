#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previous;
    
};
void enqueue(Node* &front , Node* &rear , int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    if(front==NULL){
        front = rear = newNode;
    }
    rear->next = newNode;
    newNode->previous = rear;
    rear = newNode;
    
}
void dequeue(Node*&front , Node*&rear){
    Node*temp = front;
    cout << front->data << " ";
    front =  front->next;
    front->previous = NULL;
    delete temp;
}
void display(Node* front , Node* rear){
    while(front!=NULL){
        cout << front->data << " ";
        front = front -> next;
    }
    cout << endl;
}
int main(){
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(front ,rear ,10);
    enqueue(front ,rear ,30);
    enqueue(front ,rear ,50);
    enqueue(front ,rear ,70);

    display(front ,rear);

    dequeue(front, rear);
    dequeue(front, rear);
    dequeue(front, rear);

}