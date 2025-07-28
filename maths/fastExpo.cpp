#include<iostream>
using namespace std;

int fastExpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a;
        }
        b = b >> 1;
        a = a * a;

    }
    return res;
}

int main(){
    int n = 3;
    int m = 5;
    int expoVal = fastExpo(n, m);
    cout << "Exponent of 3, 5 is " << expoVal << endl;
    return 0;
}