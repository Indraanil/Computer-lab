// #include <iostream>
// using namespace std;

// bool isempty(int top){
//     return top==-1;
// }
// bool isFull(int size , int top){
//     return top == size-1;
// }
// void push(int n , int st[] , int size,int &top ){
//     if(isFull(size , top)){
//         cout << "Stack is Full Cannot psuhed" << endl;
//     }else{
//         top++;
//         st[top] = n;
//     }
// }
// void pop(int &top , int st[]){
//     if(isempty(top)){
//         cout << "Cannot pop stack is empty" << endl;
//     }else{
//         cout << "Top element is pop" <<  st[top] << " ";
//         top--;
//     }
// }
// void peek(int &top , int st[]){
//     if(isempty(top)){
//         cout << "Stack is empty" << endl;
//     }else{
//         cout << st[top] ; 
//     }
// }
// void display(int top , int st[]){
//     if(isempty(top)){
//         cout << "Nothing to display " << endl;
//     }
//     for(int i = 0 ;i<=top;i++){
//         cout << st[i] << " ";
//     }
// }




// struct Node
// {
//     int data;
//     Node* next ;
// };
// bool isEMPTY(Node* &head){
//     return head == NULL;
// }
// void pushL(Node* &head , int n){
//     Node* newNode = new Node;
//     newNode->data = n;
//     newNode->next = head;
//     head = newNode;
// }
// void popL(Node* &head){
//     Node* temp = head;
//     cout << temp->data << endl ;
//     head = head->next;
//     delete temp;

// }
// void display(Node* head){
//     Node* current = head;
//     while(current!=NULL){
//         cout << current->data << " ";
//         current = current->next;
//     }
//     cout << endl;
// }
// int main(){
//     int st[7];
//     int top=-1;
//     int size  =7;
//     // push(5,st,7,top);
//     // push(9,st,7,top);

//     // display(top,st);
//     // pop(top , st);
//     // display(top,st);
//     // peek(top , st);
    
//     // Node* head = NULL;
//     // pushL(head,8);
//     // pushL(head,4);
//     // pushL(head,2);

//     // display(head);

//     // popL(head);
//     // display(head);


//     cout << " 1 .Implement stack using array " << endl;
//     cout << " 2 .Implement stack using Linked list  " << endl;
//     cout << "Choos the option " << endl;
//     int n;
//     cin >> n;
//     switch(n){
//         case 1:
//         cout << "You are implementing stack using array " << endl;
//         while(true){
//         cout << "---------Which operation you want to do -------- \n 1.push \n 2.pop \n 3.dispaly";
//         int op;
//         cin >> op;
//         if(op==1){
//             int  element;
//         cout << "Enter  elements you want to add in stack" << endl;
//         cin >> element;
//         push(element , st, size ,top);
//         }
//         if(op==2){
//             cout << "Element will pop .. " << endl;
//             pop(top , st);
//         }
//         if(op==3){
//             cout <<" displaying stack ... "<< endl;
//             display(top,st);
//         }

        
//         } 
        

//     }
    
// }


#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

bool isFull(int size , int &top){
    return (top == size-1);
}
bool isEmpty(int top){
    return (top == -1);
}
void push(int st[] , int &top , int val , int size){
    if(isFull(size , top)){
        cout << "stack is full cannot push" << endl;
        return;
    }
        top++;
        st[top] = val;
    
}
void pop(int st[] , int &top){
    if(isEmpty(top)){
        cout << "stack is empty nothing to display " << endl;
        return;
    }else{
        cout << st[top] << endl;
        top--;
    }
}
void peek(int st[] , int &top){
    if(isEmpty(top)){
        cout << "Stack is empty  " << endl;
        return;
    }else{
        cout << st[top] << endl;
    }
}
void display(int st[] , int &top ){
    if(isEmpty(top)){
        cout << "Nothing to display" << endl;
    }else{
        for(int i =0;i<=top;i++){
            cout << st[i] << " ";
        }
    }
}

void lkpush(Node* &head , Node* &tail , int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}
void popl(Node*&head , Node*&tail ){
    Node* curr = head;
    cout << curr->data << endl;
    head = head->next;
    delete curr;
}
void displayl(Node*&head , Node*&tail){
    if(head == NULL){
        cout << "Nothing to display " << endl;
    }else{
        Node* curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    cout << endl;

}
int main(){
    int top = -1;
    int size = 5;
    int st[size] ;
    // push(st , top , 10 ,size);
    // push(st , top , 20 , size);
    // push(st , top , 30 ,size);
    // push(st , top , 40 , size);
    // push(st , top , 50 ,size);

    // pop(st ,top);
    // peek(st , top);
    // display(st , top);

    Node* head = NULL;
    Node* tail = NULL;

    lkpush(head , tail ,60);
    lkpush(head , tail ,70);
    lkpush(head , tail ,80);
    lkpush(head , tail ,90);

    displayl(head , tail);

    popl(head , tail );
}