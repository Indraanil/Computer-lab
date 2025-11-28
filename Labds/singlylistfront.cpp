// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* next;
// };
// void frontsingly(Node* &head  , int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
// }
// void BackSingly(Node*& head ,Node*& rear , int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = NULL;
//     if(head == NULL)
// {
//     head = rear = newNode;

// }
// rear->next = newNode;
// rear = newNode;
// }
// void deletefront(Node*&head){
//     Node* temp = head;
//     head = head->next;
//     cout << temp->data ;
//     delete temp;
//     cout << endl;
// }
// void deleteBack(Node*&head , Node*&rear){
//     if(head == rear){
//         delete head;
//         head = rear = NULL;
//     }
//      Node* temp = head;
//     while(temp->next->next!=NULL){
//         temp = temp->next;
//     }
//     cout << temp->next->data << endl;
//     delete temp->next;
//     temp->next = NULL;
// }
// void insertPosition(Node* &head , int positon ,int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = NULL;

//     if(positon==1){
//         newNode->next = head;
//         head = newNode;
//     }
//     Node* temp = head;
//     for(int i =1 ; i<positon-1;i++){
//         temp = temp->next;
//     }
//    newNode->next = temp->next;
//    temp->next = newNode;
// }
// void deletePositon(Node*&head , int position){
//     if(position==1){
//         Node* temp = head;
//         cout << temp->data << " ";
//         head = head->next;
//         delete temp;
//     }
//     Node* temp = head;
//     for(int i =1;i<position-1;i++){
//         temp = temp ->next;
//     }
//     Node* current = temp->next;
//     temp->next = current->next;
//     delete current;
// }
// void displayFront(Node* head , Node* rear){
//     Node* temp = head;
//     while(temp!=NULL){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }
// void displayBack(Node* head , Node*rear){
//     Node* temp = head;
//     while(head!=NULL){
//         cout << temp->data << " ";
//         temp=temp->next;
//     }
// }
// int main(){
//     Node* head = NULL;
//     Node* rear = NULL;
//     frontsingly(head , 10);
//     frontsingly(head , 20);
//     frontsingly(head , 30);
//     frontsingly(head , 40);
//     frontsingly(head , 50);

//     displayFront(head , rear);
// deletefront(head);
// displayFront(head , rear);

// BackSingly(head , rear ,90);
// BackSingly(head , rear ,30);
// BackSingly(head , rear ,40);

// displayBack(head , rear);
// deleteBack(head , rear);
// deleteBack(head , rear);
// displayBack(head , rear);

// deleteBack(head , rear);
// displayBack(head , rear);

//     insertPosition(head , 3, 19);
//     displayFront(head , rear);
//     deletePositon(head , 3);
//     displayFront(head , rear);

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

void sinlgyfront(Node *&head, Node* tail , int val)
{
    Node *newNode = new Node(val);

    if(head == NULL){
        head = tail = newNode;
    }
    newNode->next = head;
    head = newNode;
}
void sniglyback(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {

        tail->next = newNode;
        tail = newNode;
    }
}
void deltefront(Node*&head){
    if(head == NULL){
        cout << "Nothing to delete " << endl;
    }else{
        Node* curr = head;
        head = head->next;
        cout << curr->data << " ";
        delete curr;
        
    }
    cout << endl;
}

void deleteBack(Node* &head , Node*&tail ){
    if(head == NULL){
        cout << "Nothing to delete " << endl;
        return;
    }
    if(head == tail){
        cout << head->data << " ";
        delete head;
        head = tail =NULL;
    }
    else {
        Node* curr = head;
        while(curr->next!= tail){
            curr  = curr->next;
        }
        cout << tail->data << endl;
        delete tail;
        tail = curr;
        curr->next = NULL;
        
    }
}

void display(Node* head , Node* tail){
    if(head == NULL){
        cout << "nothing to delete" << endl;
    }else{
        Node* curr= head;
       while(curr!=NULL){
        cout << curr->data << " ";
        curr = curr ->next;
       }
    }
}
void deletefrompostion(Node*&head , Node*&tail  ,int postion){
    if(postion<=0){
        cout << "Invalid postion" << endl;
        return;
    }
    if(head == NULL){
        cout << "Nothing to display " << endl;
    }else{
        if(head == tail){
            cout << head->data << endl;
            delete head;
            head = tail = NULL;
        }
        if(postion == 1){
            Node*  curr = head;
            cout << curr->data << endl;
            head = head->next;
            delete curr;
            return;
        }
        Node* temp = head;
        for(int i =1 ;i<postion-1;i++){
            if(temp == NULL){
                cout << "invalid pso"<<endl;
                return;
            }
            temp = temp->next;
        }
        Node* curr =  temp->next;
        temp->next = curr->next;
        cout << curr->data << " ";
        delete curr;
    }
}
void insertpositon(Node*&head, Node*&tail , int postion , int val){
    if(postion<=0){
        cout << "Invalid postion" <<  endl;
    }
    Node* newNode = new Node(val);
    if(postion == 1){
        newNode->next = head;
        head = newNode;
        if(tail == NULL)
        tail = newNode;
        return;
    }else{
        Node* curr = head;
        for(int i =1;i<postion-1;i++){
            if(curr == NULL){
                cout << "position not valid" << endl;
            }
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;

        if(newNode->next == NULL){
            tail = newNode;
        }
        
    }
}
int main()
{
    Node *head = NULL;
    Node* tail = NULL;
//     sinlgyfront(head ,10);
//     sinlgyfront(head ,20);
//     sinlgyfront(head ,30);
//     sinlgyfront(head ,40);
//     sinlgyfront(head ,50);
//     sinlgyfront(head ,60);

//     display(head , tail);
// cout <<  endl;
//     deltefront(head);
//     display(head , tail);

    sniglyback(head , tail , 10);
    sniglyback(head , tail , 20);
    sniglyback(head , tail , 30);
    sniglyback(head , tail , 40);
    sniglyback(head , tail , 50);
    sniglyback(head , tail , 60);

    display(head , tail);
cout << endl;

    // deleteBack(head , tail);
    // display(head , tail);
cout << endl;   
// insertpositon(head , tail , 6,80);
deletefrompostion(head , tail ,3);
cout << endl;
    display(head , tail);



}