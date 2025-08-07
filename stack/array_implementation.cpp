#include<iostream>
using namespace std;

class Stack {
    public:
        int *arr;
        int limit;
        int maxSize;

        Stack(int maxSize){
            this->maxSize = maxSize;
            arr = new int[maxSize];
            limit = -1;
        }

        void push(int data){
            if(limit == maxSize-1){
                cout << "Stack overflow!" << endl;
                return;
            }

            limit++;
            arr[limit] = data; 
        }

        void pop(){
            if(limit == -1){
                cout << "Stack underflow!" << endl;
            } else {
                limit--;
            }
        }

        bool isEmpty(){
            return (limit < 0) ? true : false;
        }

        int size(){
            return limit+1;
        }

        int top(){
            return (limit < 0) ? -1 : arr[limit];
        }
};

int main(){
    Stack s(10);

    s.push(10);
    s.push(61);

    cout << "Current size of stack :" << s.size() << endl;
    cout << "Top element :" << s.top() << endl;
    
    s.pop();
    cout << "Current size of stack :" << s.size() << endl;
    cout << "Top element :" << s.top() << endl;

    if(s.isEmpty()){
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    s.pop();

       if(s.isEmpty()){
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    cout << "Current size of stack : " << s.size() << endl;

    return 0;
}