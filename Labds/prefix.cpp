// #include <iostream>
// #include <stack>
// #include <string>
// #include <cctype>
// #include <cmath>
// using namespace std;

// int precedence(char op) {
// if (op == '^') return 3;
// if (op == '*' || op == '/') return 2;
// if (op == '+' || op == '-') return 1;
// return 0;
// }

// string infixToPostfix(const string& infix) {
// stack<char> s;
// string postfix = "";
// for (char c : infix) {
// if (isalnum(c)) {
// postfix += c;
// }
// else if (c == '(') {
// s.push(c);
// }
// else if (c == ')') {
// while (!s.empty() && s.top() != '(') {
// postfix += s.top(); s.pop();
// }
// if (!s.empty()) s.pop(); // Pop '('
// }
// else { // Operator
// while (!s.empty() && precedence(c) <= precedence(s.top())) {
// postfix += s.top(); s.pop();
// }
// s.push(c);
// }
// }
// while (!s.empty()) {
// postfix += s.top(); s.pop();
// }
// return postfix;
// }




#include <iostream>
#include <stack>
using namespace std;


int precedence(char op){
        if(op == '^')  
        return 3;
        if(op == '*' || op == '/')
        return 2;
        if(op == '+' || op == '-')
        return 1;

    }
bool isLeftAssociatiive(char op){
    return(op != '^');
}
bool isOperator(char c){
    return(c == '+' || c == '-' || c == '/' || c == '*' || c=='^');

}

string infixToPostfix(string infix){
    stack <char> st;
    string postfix = " ";
    for(char token:infix){
        if(isspace(token)){
            continue;
        }else if(isalnum(token)){
            postfix = postfix + token;
        }else if(token == '('  ){
            st.push(token);
        }else if(token == ')'){
            while(!st.empty() && st.top() !='(' ){
                postfix = postfix + st.top(); // take the operator from the top and add it to postfix

                st.pop(); // remove that operator from the stac
            }
             if (!st.empty()) st.pop(); // Pop '('
        }else if(isOperator(token)){
            while(!st.empty() && isOperator(st.top())){
                char topop = st.top();
                if(
                    (precedence(topop) > precedence(token)) || 
                    (precedence(topop) == precedence(token) && isLeftAssociatiive(token)) ){
                        postfix = postfix + topop;
                        st.pop();
                    }else{
                        break;

                    }
                
            
            }
                st.push(token);

        }
    }
    // Pop remaining operators
     while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
     return postfix;
} 

int main(){
    string infix;
    cout << "Enter infix expression";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "postfix expression" << postfix <<endl;
}





#include <iostream>
#include <stack>
using namespace std;

int precedence(char op){
    if(op ==  '^')
    return 3;
    if(op == '*' || op == '/')
    return 2;
    if(op == '+' || op == '-')
    return 1;
}
bool isLeftAssociativity(char op){
    return (op!='^');
}
bool isOperator(char c){
    return(c =='+'|| c=='-'|| c=='*' || c=='=' || c=='/');
}
string infixTopostfix( string infix){
    stack <char> st;
    string postfix = " ";
    for(char token:infix){
        if(isalnum(token)){
            postfix = postfix + token;
        }else if(token == '(' ){
            st.push(token);
        }else if(token == ')'){
            while(!st.empty() && st.top()!='(' ){
                postfix = postfix + st.top();
                st.pop();
            }
             if(isOperator(token)){
                
            }
        }
    }
}