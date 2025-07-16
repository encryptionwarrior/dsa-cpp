#include <iostream>
using namespace std;

void PrintNumN();
void PrintSumN();
void PrintSumEvenN();
void fahrenHeightCelcius();
void CelciusfahrenHeight();
void primeToN();
void checkIsPrime();
void fibonacciSeries();
void subtractProductAndSum();

int main(){
    // PrintNumN();
    // PrintSumN();
    // PrintSumEvenN();
    // fahrenHeightCelcius();
    // CelciusfahrenHeight();
    // primeToN();
    // checkIsPrime();
    // fibonacciSeries();
    subtractProductAndSum();
    return 0;
}

void PrintNumN(){
    int n = 50;
    int index = 1;
    while(index <= n){
        cout << index;
        index++;
    }
}


void PrintSumN(){
    int n = 50;
    int i = 1;
    int sum = 0;
    while(i <= n){
        sum = sum + i;
        i = i + 1;
    }
    cout << endl;
    cout << "Value of sum " << sum << endl;
}


void PrintSumEvenN(){
    int n = 50;
    int i = 1;
    int sum = 0;
    while(i <= n){
        if(i % 2 == 0){
            sum = sum + i;
        }
        i = i + 1;
    }
    cout << endl;
    cout << "Value of sum even numbers  " << sum << endl;
}

void fahrenHeightCelcius(){
    float fahrenheight, celcius;
    fahrenheight = 98;
    celcius = (fahrenheight - 32) * 5/9;

    cout << "Temprature in celcius " << celcius << endl;
}


void CelciusfahrenHeight(){
    float fahrenheight, celcius;
    celcius = 36.6667;
    fahrenheight = (celcius * 9/5) + 32 ;

    cout << "Temprature in fahren height " << fahrenheight << endl;
}

void primeToN(){
    int n = 59;
    int i = 2;
    while(i <= n){
        int j = 2;
        bool isPrime = true;
        while(j <= i/2){
            if(i % j == 0){
                isPrime = false;
                break;
            }
            j = j + 1;
        }

        if(isPrime){
            cout << "Print prime => " << i <<endl;
        }
        i = i + 1;
    }
}

void checkIsPrime(){
    int n = 103;
    bool isPrime = true;

    if(n <= 1){
        cout << "Number 1 or smaller can not be prime => " << n << endl;
        return;
    }

    for(int i = 2; i < n/2; i++){
        cout << "check loop number of i " << i << endl;
        if(n % i == 0){
            isPrime =  false;
            break;
        }
    }

    if(isPrime){
        cout << "Number is prime => " << n << endl;
    } else {
        cout << "Number is not prime => " << n << endl;
    }
}

void fibonacciSeries(){
    int n = 20;
    int a = 0;
    int b = 1;

    cout << "Value of Fibonacci Series " << a << ", " << b ;
    for(int i = 1; i <= n; i++){
        int nextNum = a + b;
        a = b;
        b = nextNum;
        cout << ", " << nextNum ;
    }
}


void subtractProductAndSum(){
    int n = 119;
    int prod = 1;
    int sum = 0;
    while(n != 0){
        int digit = n % 10;
        prod = prod * digit;
        sum = sum + digit;
        n = n / 10;
        cout << "check digit, prod and sum => " << digit << ", " << prod <<  ", " << sum << ", " << n << endl;
    }

    int ans = prod - sum;

    cout << "subtract product and sum => " << ans << endl;
}