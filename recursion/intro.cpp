#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n - 1);
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int tailRecursivefactorial(int n, int result = 1){
    if(n == 0){
        return result;
    }

    return tailRecursivefactorial(n - 1, result * n);
}

vector<int>memo(100, -1);
int fibonacciMemoized(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    if(memo[n] !=  -1) return memo[n];

    memo[n] =  fibonacci(n - 1) + fibonacci(n - 2);
}



int main(){
    int number = 10;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    cout << "Fibonaaci of " << number << " is " << fibonacci(number) << endl;
    cout << "Factorial of " << number << " is " << tailRecursivefactorial(number) << endl;
    cout << "Fibonaaci of " << number << " is " << fibonacciMemoized(number) << endl;
    return 0;
}