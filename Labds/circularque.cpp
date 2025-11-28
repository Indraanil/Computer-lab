// #include <iostream>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
// };

// void circularEn(Node* &front , Node* &rear , int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     if(front==NULL){
//         front = rear = newNode;
//         newNode->next = newNode;
//     }
//     newNode->next =  front;
//     rear->next = newNode;
//     rear = newNode;
// }
// void circulauDeq(Node*&front , Node*&rear){
//     if(front == rear){
//         cout << front->data << endl;
//         delete front;
//         front  = rear = NULL;
//     }
//     Node* temp = front;
//     front = front->next;
//     cout << temp->data << endl;
//     delete temp;
//     rear->next = front;
// }
// void disply(Node* front , Node* rear){
//     Node*temp = front;
//     do{
//         cout << temp->data << " ";
//         temp = temp->next;
//     }while(temp!=front);
//     cout << endl;
// }
// int main(){
//     Node* front =NULL ;
//     Node* rear  = NULL;
//     circularEn(front , rear , 91);
//     circularEn(front , rear , 93);
//     circularEn(front , rear , 94);

//     disply(front ,rear);
//     circulauDeq(front , rear);
//     disply(front ,rear);

// }

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool isFULL(int size, int rear)
{
    return (rear == size - 1);
}
bool isEmpty(int front, int rear)
{
    return (front == -1 && rear == -1);
}
void enqueue(int &front, int &rear, int q[], int value, int size)
{
    if (isFULL(size, front))
    {
        cout << "Queue is overflow" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    q[rear] = value;
}
void dequeue(int &front, int q[], int &rear, int size)
{
    if (isEmpty(front, rear))
    {
        cout << "queue is empty" << endl;
    }

    if (front == rear)
    {
        cout << q[front];
        front = rear = -1;
    }
    else
    {
        cout << q[front] << endl;
        front++;
    }
    cout << endl;
}
void circularEnqueue(int &front, int &rear, int q[], int size, int value)
{
    if (front == (rear + 1) % size)
    {
        cout << "queue is full ";
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        q[rear] = value;
    }
}

void circularDequeue(int &front, int &rear, int q[], int size)
{
    if (front == -1)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << q[front];
        front = (front + 1) % size;
    }
    cout << endl;
}
void display(int front, int rear, int q[])
{
    for (int i = front; i <= rear; i++)
    {
        cout << q[i] << " ";
    }
}

void frontenqueueLinkede(int val, Node *&front, Node *&rear)
{
    Node *newNode = new Node(val);

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        rear->next = NULL;
    }
    else
    {
        newNode->next = front;
        front = newNode;
    }
}

void backenqueueLinked(int val, Node *&front, Node *&rear)
{
    Node *newNode = new Node(val);
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        newNode->next = NULL;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFrontdequeue(Node *&front, Node *&rear)
{
    if (front == rear)
    {
        cout << front->data << " ";
        delete front;
        front = rear = NULL;
    }
    else
    {

        Node *curr = front;
        front = front->next;
        cout << curr->data << " ";
        delete curr;
    }
}

void deletebackdequeue(Node *&front, Node *&rear)
{
    if (front == rear)
    {
        cout << front->data << " ";
        delete front;
        front = rear = NULL;
    }
    Node *curr = front;
    while (curr->next != rear)
    {
        curr = curr->next;
    }
    curr->next = NULL;
    delete rear;
    rear = curr;
}
void circularEnqueueList1(Node *&front, Node *&rear, int val)
{
    Node *newNode = new Node(val);
    newNode->next = front;

    if (front == NULL)
    {
        front = rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}
void circularEnqueueList2(Node *&front, Node *&rear, int val)
{
    Node *newNode = new Node(val);
    if (front == NULL)
    {
        front = rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = front;
        rear->next = newNode;

        front = newNode;
    }
}
void displayCircular(Node *&front, Node *&rear)
{
    if (front == NULL)
    {
        cout << "Nothing to display" << endl;
    }
    else
    {
        Node *curr = front;
        do
        {
            cout << curr->data << " ";
            curr = curr->next;

        } while (curr != front);
    }
}

void display(Node *&front, Node *&rear)
{
    if (front == NULL)
    {
        cout << "nothing to display" << endl;
    }
    Node *curr = front;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    // int size = 100;
    // int q[size];
    // int front = -1;
    // int rear = -1;

    // enqueue(front, rear, q, 20, size);
    // enqueue(front, rear, q, 30, size);
    // enqueue(front, rear, q, 40, size);
    // enqueue(front, rear, q, 50, size);
    // enqueue(front, rear, q, 60, size);

    //     display(front, rear, q);
    // cout << endl;
    //     dequeue(front , q , rear ,size);
    //     display(front, rear, q);

    // circularEnqueue(front ,rear ,q ,size , 10);
    // circularEnqueue(front ,rear ,q ,size , 20);
    // circularEnqueue(front ,rear ,q ,size , 30);
    // circularEnqueue(front ,rear ,q ,size , 40);
    // circularEnqueue(front ,rear ,q ,size , 50);
    // circularEnqueue(front ,rear ,q ,size , 60);

    // display(front , rear , q);

    // cout << endl;

    // circularDequeue(front , rear , q , size , 10);

    // display(front , rear ,q);

    Node *front = NULL;
    Node *rear = NULL;

    frontenqueueLinkede(10, front, rear);
    frontenqueueLinkede(20, front, rear);
    frontenqueueLinkede(30, front, rear);
    frontenqueueLinkede(40, front, rear);
    frontenqueueLinkede(50, front, rear);

    backenqueueLinked(60, front, rear);
    display(front, rear);
    cout << endl;
    deleteFrontdequeue(front, rear);
    cout << endl;

    display(front, rear);
    cout << endl;

    deletebackdequeue(front, rear);

    display(front, rear);
    cout << endl;

    circularEnqueueList1(front, rear, 30);
    displayCircular(front, rear);
    cout << endl;
    circularEnqueueList1(front, rear, 80);
    displayCircular(front, rear);
    cout << endl;
    circularEnqueueList2(front, rear, 90);
    displayCircular(front, rear);
}