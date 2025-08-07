#include<iostream>
using namespace std;

class TwoStack {
    public:
        int *arr;
        int limit1;
        int limit2;
        int maxSize;

        TwoStack(int size){
            maxSize = size;
            arr = new int[size];
            limit1 = -1;
            limit2 = size;
        }

        void push1(int data){
            if(limit2 - limit1 > 1){
                limit1++;
                arr[limit1] = data;
            } else {
                cout << "Stack overflow!" << endl;
            }
        }


        void push2(int data){
            if(limit2 - limit1 > 1){
                limit2--;
                arr[limit2] = data;
            } else {
                cout << "Stack overflow!" << endl;
            }
        }

        void pop1(){
            if(limit1 == -1){
                cout << "Stack underflow!" << endl;
            } else {
                limit1--;
            }
        }
        void pop2(){
            if(limit2 == maxSize){
                cout << "Stack underflow!" << endl;
            } else {
                limit2++;
            }
        }
};

int main(){

    TwoStack st(5);

    st.push1(23);
    st.push2(65);

    st.push1(94);
    st.push1(11);
    st.push1(32);

    st.pop2();
    st.pop1();
    st.pop1();


    cout << "Limit 1: " << st.limit1 + 1 << endl;
    cout << "Limit 2: " << st.limit2 + 1 << endl;
    cout << "Stack is : " << st.arr[st.limit1] << endl;
    cout << "Stack is : " << st.arr[st.limit2] << endl;




    
	return 0;
}