#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse(stack<int> &st){
    queue<int> q;
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
}
void display(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
int main(){
    stack <int> st;
    reverse(st);
   display(st);
    
}