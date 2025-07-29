#include <iostream>
using namespace std;

int countDistinctWayToClimbStairs(int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }

    return countDistinctWayToClimbStairs(n - 1) + countDistinctWayToClimbStairs(n - 2);
}


int fibonacci(int n){
    if(n <= 1){
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void sayDigit(int n, string arr[]){
    if(n == 0){
        return ;
    }

    int digit = n % 10;
    n = n / 10;

    sayDigit(n, arr);

    cout << "Digit => " << arr[digit] << endl;
}

void reachHome(int src, int des){
    cout << "Source  " << src << " Destination " << des << endl;

    if(src == des){
        cout << "Pahuch gaya (Reached Home)" << endl;
        return;
    }

    src++;
    reachHome(src, des);

}

int main()
{
    int n = 7;
    int countSteps = countDistinctWayToClimbStairs(n);
    cout << "Count stairs " << countSteps << endl;


    int fiboSeries = fibonacci(n);
    cout << "Count stairs " << fiboSeries << endl;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigit(412, arr);

    reachHome(1, 6);
    return 0;
}