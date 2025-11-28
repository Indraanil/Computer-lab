#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string str){
    stack <char> st;
    for(char ch:str){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            if(st.empty()) return false;

            char top = st.top();
            st.pop();

            if(ch == ')' && top!='('    || ch == '}' && top!= '{' || ch == ']' && top!='['){
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    string expression ;
    cin >> expression;
    if(isValid(expression)){
        cout << "Matched" << endl;
    }else{
        cout << "Not matched" << endl;
    }
}