#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(10);
    s.push(61);

    cout << "Current size of stack : " << s.size() << endl;
    cout << "To element : " << s.top() << endl;

    s.pop();
    cout << "Current size of stack : " << s.size() << endl;
    cout << "To element : " << s.top() << endl;
    

    if(s.empty()){
        cout << "stack is empty!" << endl;
    } else {
        cout << "stack is not empty!" << endl;
    }
    
    s.pop();
    
    if(s.empty()){
        cout << "stack is empty!" << endl;
    } else {
        cout << "stack is not empty!" << endl;
    }

    cout << "Current size of stack: " << s.size() << endl;
}