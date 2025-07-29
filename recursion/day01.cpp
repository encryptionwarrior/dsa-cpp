#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }

    int smallerProblem = factorial(n-1);
    int biggerProblem = n * smallerProblem;
    return biggerProblem;
}


int powerNum(int n){
    if(n == 0){
        return 1;
    }

    return 2 * powerNum(n - 1);
}

int main(){
    int n = 5;

    int fact = factorial(n);
    cout << "check factorial " << fact << endl;

    int pow = powerNum(n);
    cout << "Check power " << pow << endl;
}