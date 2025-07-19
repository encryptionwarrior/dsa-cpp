#include <iostream>
using namespace std;

void printAlphabetSquare();
void printAlphabetTrianle();
void printReverseAlphabetTrianle();
void printInvertedSapceAlphabetTrianle();
void printReverseAngleTrianle();
void NumberPyramid();
void dabanggPattern();


int main(){
    // printAlphabetSquare();
    // printAlphabetTrianle();
    // printReverseAlphabetTrianle();
    // printInvertedSapceAlphabetTrianle();
    // printReverseAngleTrianle();
    // NumberPyramid();
    dabanggPattern();
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

void NumberPyramid () {
    int height = 5;
    for(int i = 1; i <= height; i++){
        for(int k = 1; k <= (height - i); k++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        for(int l = i - 1; l >= 1; l--){
            cout << l;
        }
        cout << endl;
    }
}

void dabanggPattern(){
    int h = 5;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <=( h - i + 1); j++){
            cout << j << " ";
        }
        for(int k = 1; k <=( i); k++){
            cout << "* ";
        }
        for(int k = (i - 1); k >= 1; k--){
            cout << "* ";
        }

        for(int l = (h - i + 1); l >= 1; l--){
            cout << l << " ";
        }
        cout << endl;
    }
}