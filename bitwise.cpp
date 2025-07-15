#include <iostream>
using namespace std;

void andOperator();
void OROperator();
void NOTOperator();
 void XOROperator();
 void LeftOperator();
 void RightOperator();
 void DecToBin();
 void BinToDec();
 void NegativeDecToBin();

int main(){
    cout << "Is this file running ++++" << endl;
    andOperator();
    OROperator();
    NOTOperator();
    XOROperator();
    LeftOperator();
    RightOperator();
    DecToBin();
    BinToDec();
    NegativeDecToBin();
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
void XOROperator(){
    int a = 5;
    int b = 4;
    int result = a^b;
    cout << " This is a^b =>  " << result << endl; 
}
void LeftOperator(){
    int a = 5;
    int result = a << 1;
    cout << " This is a << 1 =>  " << result << endl; 
}
void RightOperator(){
    int a = 10;
    int result = a >> 1;
    cout << " This is a >> 1 =>  " << result << endl; 
}

void DecToBin(){
    int a = 13;
    int arr[32];
   int index = 0;
    while(a > 0){
        arr[index] = a%2;
        a = a/2;
        index++;
    }

    cout << "Binary " ;
    for(int i = index - 1; i >=0; i--){
        cout << arr[i];
    }
}

void BinToDec(){
    int binary = 1101;
    int base = 1;
    int decimal = 0;

  while(binary > 0){
    int lastDigit = binary % 10;
    decimal += lastDigit * base;
    base *=2;
    binary /=10;
  }

  cout << "decimal numer ++" << decimal << endl;
}

void NegativeDecToBin() {
    int num = -13;
    if (num >= 0) {
        cout << "Error: Input must be a negative number." << endl;
        return;
    }

    int bits = 8;
    int binary[8] = {0};

    // Step 1: Convert positive version to binary
    int positive = -num;
    int temp[8] = {0};
    int index = bits - 1;
    while (positive > 0 && index >= 0) {
        temp[index--] = positive % 2;
        positive /= 2;
    }

    // Step 2: Invert bits (1's complement)
    for (int i = 0; i < bits; i++) {
        temp[i] = 1 - temp[i];
    }

    // Step 3: Add 1 to get 2's complement
    int carry = 1;
    for (int i = bits - 1; i >= 0; i--) {
        int sum = temp[i] + carry;
        binary[i] = sum % 2;
        carry = sum / 2;
    }

    // Print result
    cout << "Binary (8-bit Two's Complement) of " << num << " is: ";
    for (int i = 0; i < bits; i++) {
        cout << binary[i];
    }
    cout << endl;
}