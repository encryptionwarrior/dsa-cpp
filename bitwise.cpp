#include <iostream>
using namespace std;

void andOperator();
void OROperator();
void NOTOperator();

int main(){
    cout << "Is this file running ++++" << endl;
    andOperator();
    OROperator();
    NOTOperator();
    return 0;
}

void andOperator(){
    int a = 6;
    int b = 5;
    int result = a & b;
    cout << " This is a & b =>  " << result << endl; 
}


void OROperator(){
    int a = 8;
    int b = 5;
    int result = a | b;
    cout << " This is a | b =>  " << result << endl; 
}
void NOTOperator(){
    int a = 4;
    int result = ~a;
    cout << " This is ~a =>  " << result << endl; 
}