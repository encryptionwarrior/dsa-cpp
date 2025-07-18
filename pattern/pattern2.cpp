#include <iostream>
using namespace std;

void printAlphabetSquare();
void printAlphabetTrianle();
void printReverseAlphabetTrianle();
void printInvertedSapceAlphabetTrianle();
void printReverseAngleTrianle();


int main(){
    // printAlphabetSquare();
    // printAlphabetTrianle();
    // printReverseAlphabetTrianle();
    // printInvertedSapceAlphabetTrianle();
    printReverseAngleTrianle();
    return 0;
}

void printAlphabetSquare(){
    int height = 4;
    char ch = 'A';
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= height; j++){
            cout << ch << " ";
        }
        cout << endl;
        ch++;
    }
    cout << endl;
}
void printAlphabetTrianle(){
    int height = 4;
    char ch = 'A';
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
        ch++;
    }
    cout << endl;
}

void printReverseAlphabetTrianle(){
    int height = 4;
    char ch = 'A';
    for(int i = 1; i <= height; i++){
        char val = ch + height - i;
        for(int j = 1; j <= i; j++){
            cout << val << " ";
            val++;
        }
        cout << endl;
    }
    cout << endl;
}
void printInvertedSapceAlphabetTrianle(){
    int height = 4;
    char ch = 'A';
    for(int i = 1; i <= height; i++){
        
        for(int k = 1; k <= (height - i); k++){
            cout << " ";
        }   
        for(int j = 1; j <= i; j++){
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;
}
void printReverseAngleTrianle(){
    int height = 4;
    char ch = 'A';
    for(int i = height; i >= 1; i--){
        
        for(int j = i; j >= 1; j--){
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << endl;
}