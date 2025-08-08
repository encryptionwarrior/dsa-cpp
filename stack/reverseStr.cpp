#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseStr() {
    string str, answer;
    stack<char> s;

    cout << "Enter the String : ";
    getline(cin, str); // Will work properly if no cin >> was used before

    for (char ch : str) {
        s.push(ch);
    }

    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }

    cout << "Original string : " << str << endl;
    cout << "Reversed string : " << answer << endl;
}

void deleteMiddle(stack<int> &st, int count, int size){
    if(count == size/2){
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();

    deleteMiddle(st, count + 1, size);

    st.push(top);
}

void testDeleteMiddle(){
    stack<int> st;
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);

    int count = 0 ;
    int n = st.size();

    cout << "Size of stack : " << st.size() << endl;

    deleteMiddle(st, count, n);

    cout << "Size of stack : " << st.size() << endl;
}

bool matches(char a, char b){
    switch(a){
        case ')':
            return (b == '(') ? true : false;
        case '}':
            return (b == '{') ? true : false;
        case ']':
            return (b == '[') ? true : false;
        default:
            return false;
    }
}

bool isValid(string str){
    stack<char> st;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '{'  || ch == '['){
            st.push(ch);
        } else {
            if(!st.empty() && matches(ch, st.top())){
                st.pop();
            } else {
                return false;
            }
        }
    }

    return (st.empty()) ? true : false;
}

void validParenthesis(){
    string str;
    cout << "Enter the expression : ";

    getline(cin, str);

    if(isValid(str)){
        cout << "Balanced " << endl;
    } else {
        cout << "Not balanced" << endl;
    }
}

void inputStack(stack<int> &st){
    int size;
    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the stack elements : ";
    for(int i = 0; i < size; i++){
        int temp;
        cin >> temp;
        st.push(temp);
    }
}

void printStack(stack<int> st){
    cout << "Stack : ";
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

void insertBottom(stack<int>&st, int data){
    if(st.empty()){
        st.push(data);
        return;
    }

    int top = st.top();
    st.pop();

    insertBottom(st, data);

    st.push(top);
}




int main(){
    reverseStr();
    testDeleteMiddle();
    validParenthesis();

    stack<int> st;

    inputStack(st);
    printStack(st);

    cout << "Inserting 10 at bottom..." << endl;
    insertBottom(st, 10);
    printStack(st);
    return 0;
}