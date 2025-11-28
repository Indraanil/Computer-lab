// #include <iostream>
// #include <stack>
// #include <cctype>
// #include <string>
// using namespace std;

// int precedence(char c ){
//     if (c == '^') return 3;
//     if(c == '*' || c == '/') return 2;
//     if(c == '+' || c == '-') return 1;
//     return 0;
// }

// string infixtoPostfix(string infix){
//     stack<char> st;
//     string postfix = "";
//     for ( char c:infix){
//     if(isalnum(c)){
//         postfix = postfix +c;
//     }
//     else if(c == '('){
//         st.push(c);
//     }
//     else if(c == ')'){
//         while(!st.empty() && st.top()!='(' ){
//             postfix += st.top();
//             st.pop();
//         }
//         st.pop();
//     }
//     else{
//         while(!st.empty() &&  precedence(st.top()) >= precedence(c)){
//             postfix += st.top();
//             st.pop();
//         }
//         st.push(c);
//     }

// }
// while(!st.empty()){
//         postfix+=st.top();
//         st.pop();
//     }
//     return  postfix;
// }

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
string infixtopostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

string postfixToinfix(string postfix)
{
    stack<string> st;
    for (char ch : postfix)
    {
        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string exp = "(" + op1 + ch + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
}
int main()
{
    string infix = "A+B*C";
    string ans = infixtopostfix(infix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}