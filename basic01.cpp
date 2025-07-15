#include <iostream> 
using namespace std;
// sum of 2 numbers

int FindSI();
int AvgNumbers();
int checkGreater();
int printNumber();
int printEvenNumber();
int sumNumbers();
int printPrime();
int main(){
    // int n, m;
    // cout << "enter values of n" << endl;;
    // cin>>n;
    // cout << "enter values of m" << endl;
    // cin >>m;
    // cout << "check number here ++" << n + m << endl;

    // cout << "check simple inetrest " << FindSI() << endl;
    // cout << "check simple inetrest " << AvgNumbers() << endl;
    // cout << "check simple inetrest " << checkGreater() << endl;
    // cout << "check simple inetrest " << printNumber() << endl;
    // cout << "check simple inetrest " << printEvenNumber() << endl;
    // cout << "check simple inetrest " << sumNumbers() << endl;
    cout << "check simple inetrest " << printPrime() << endl;
}

// find simple interest

int FindSI() {
    int p, r, t;
    cout << "enter value of P" << endl;
    cin>>p;
    cout << "enter value of R" << endl;
    cin>>r;
    cout << "enter value of T" << endl;
    cin>>t;
    return (p * t * r) / 100;

}

int AvgNumbers(){
    int a,b,c;
    cin >> a >> b >> c; 
    int avg = (a+b+c)/3;
    return avg;
}

int checkGreater(){
    int a, b;
    cin >> a >> b;
    if(a > b){
        return 1;
    } else {
        return 0;
    }
}

int checkOddEven(){
    int a;
    cin >> a;
    if(a % 2 == 0){
        return 1;
    } else {
        return 0;
    }
}

int printNumber(){
    int num;
    cin >> num;
    for(int i = 0; i < num + 1; i++){
        cout << "print number +++" << i << endl;
    }
    return 0;
}

int printEvenNumber(){
    int num;
    cin >> num;
    for(int i = 2; i < num + 1; i+=2){
            cout << "print even number +++" << i << endl;
    }
}

int sumNumbers(){
    int num;
    cin >> num;
    int sum = 0;
    for(int i = 0; i < num + 1; i++){
            sum += i;
    }
    return sum;

}

int printPrime(){
    int num;
    cin >> num;
    if(num <= 1){
        cout << " No prime numbers in this range. ++++" << endl;
        return 0;
    };

    // run loop 2 to n
    for(int i = 2; i <= num; ++i){
        bool isPrime = true;
        // i 20, j 2 * 2  < 20, false;
        // i 20, j 3 * 3  < 20, false;
        for(int j = 2; j * j <= i; ++j){
            cout << "check j * j" << j << j * j << endl;
    
             if (i % j == 0){
                isPrime = false;
                break;
                 
             }
        }
        if(isPrime){
cout << "print prime number ++" << i << endl;
        }
    }
}