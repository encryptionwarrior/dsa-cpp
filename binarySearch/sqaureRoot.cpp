#include<iostream>
using namespace std;


long long int sqrtInteger(int n){
     int s = 0;
     int e = n - 1;
    long long int mid = s + (e - s)/2;
    long long ans = -1;

    while(s <= e){
        long long int square = mid * mid;
        if(square == n) return mid;

        if(square < n){
            ans = mid;
            s = mid + 1;
        } else {
            e = mid  - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

double morePrecision(int n, int precsion, int tempSol){
    double factor = 1;
    double ans = tempSol;
    for(int i = 0; i < precsion; i++){
        factor = factor/10;
        for(double j = ans; j * j < n; j = j + factor){
            ans = j;
        }
    }

    return ans;
}

int main(){
    int n = 50;
    int tempSol = sqrtInteger(n);
    cout << "The square root of " << n << " is: " << morePrecision(n, 3, tempSol) << endl;
    return 0;
}