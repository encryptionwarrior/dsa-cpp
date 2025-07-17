#include <iostream>
#include <math.h>
#include <limits.h>
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
void BinToDec();
void DecToBin();
void reverseInt();
void isPower2();
void bitwiseComplement();
void powerMN();
void nCr();
void isEven();
void printCounting();

int main(){
    // PrintNumN();
    // PrintSumN();
    // PrintSumEvenN();
    // fahrenHeightCelcius();
    // CelciusfahrenHeight();
    // primeToN();
    // checkIsPrime();
    // fibonacciSeries();
    // subtractProductAndSum();
    // BinToDec();
    // DecToBin();
    // reverseInt();
    // isPower2();
    // bitwiseComplement();
    // powerMN();
    // nCr();
    // isEven();
    printCounting();
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
    int n = 189;
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

void BinToDec(){
    int n = 101;
    int ans = 0;
    int i = 0;
    while(n!=0){
        int digit = n % 10;
        if(digit == 1){
            ans = ans + pow(2, i);
        }
        n = n/10;
        i++;
    }
    cout << "Binary to decimal 1010 of => " << ans << endl;
}

void DecToBin(){
    int n = 3;
    int i = 0;
    int ans = 0;

    while(n != 0){
        int bit = n & 1;
        double bitVal = bit * (pow(10, i));
        ans = bitVal + ans;
        n = n >> 1;
        i++;
    }

    cout << "Decimal 7 to binary => " << ans << endl;

}

void reverseInt(){
    int n = 98709;
    int ans = 0;
    while(n != 0){
        int digit = n % 10;

        if((ans  > INT_MAX/10) || (ans < INT_MIN/10)){
            return;
        }

        ans = (ans * 10) + digit;
        n = n / 10;
    }

    cout << "Reverse of " << "98709" << " is " << ans << endl; 
}

void isPower2(){
    int n =  32768*32768;
    int ans = 1;

    for(int i = 0; i <= 30; i ++){
        if(n == ans){
            cout << "Given "<< n << " is power of 2" << endl;
            return;
        }

        if(ans < INT_MAX / 2){
            ans = ans * 2;
        }
    }

    cout << "Given "<< n << " is not power of 2" << endl;
}

void bitwiseComplement(){
int n = 9;
int m = n;
int mask = 0;


if(n == 0 ){
     cout << "compliment of bitwise is " << 1 << endl;
    return;
}

while( m!= 0 ){
    mask = (mask << 1) | 1;
    m = m >> 1;
    cout << "Check mask " << mask << " m " << m << endl;
}

int ans = ~n&mask;

    cout << "compliment of bitwise is " << ans << endl;
}

void powerMN(){
    int n1 = 2;
    int n2 = 5;

    int ans = 1;
    for(int i = 1; i <= n2; i++){
        ans = ans * n1;
    }

    cout  << "Final answer is here of power " << ans << endl;
}

int factorial(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact = fact * i;
    }

    return fact;
}

void nCr(){
    int n = 5;
    int r = 2;
    int num = factorial(n);
    int denom = factorial(r) * factorial(n-r);
    cout << "check num and denom " << num << denom << endl;
    int ans = num/denom;

    cout << "nCr is " << ans << endl;
}

void isEven(){
    int n = 41;
    if(n & 1){
        cout << "Given number is odd " << n << endl;
    } else {
         cout << "Given number is even " << n << endl;
    }
}

void printCounting(){
    int n = 30;
    cout << "counting is ";
    for(int i = 1; i <= n; i++){
        cout  << i << " " << endl;
    }
}