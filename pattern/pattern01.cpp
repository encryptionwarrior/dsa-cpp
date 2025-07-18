#include <iostream>
using namespace std;

void printSquare();
void printNumSquare();
void printNumSquare2();
void printInvertedNumSquare();
void printCountingSquare();
// void printRightAngeledTrianle();
void printRightAngeledCountTrianle();
void printRightAngeledCountTrianleJ();
void printRightAngeledInvertedCountingTrianleJ();
void printRightAngeledInvertedCountingTrianle();

int main(){
    // printSquare();
    // printNumSquare();
    // printNumSquare2();
    // printInvertedNumSquare();
    // printCountingSquare();
    // printRightAngeledTrianle();
    // printRightAngeledCountTrianle();
    // printRightAngeledCountTrianleJ();
    // printRightAngeledInvertedCountingTrianleJ();
    printRightAngeledInvertedCountingTrianle();
    return 0;
}


void printSquare(){
    int side = 4;
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

void printNumSquare(){
    int side = 4;
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){
            cout << i;
        }
        cout << endl;
    }
    cout << endl;
}
void printNumSquare2(){
    int side = 4;
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

void printInvertedNumSquare(){
    int side = 4;
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){
            cout << (side - j + 1) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void printCountingSquare(){
    int side = 4;
    int counter = 1;
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){
            cout << counter << " ";
            counter++;
        }
        cout << endl;
    }
    cout << endl;
}
void printRightAngeledTrianle(){
    int height = 4;
    char ch = '*';
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printRightAngeledCountTrianleJ(){
    int height = 4;
    for(int i = 1; i <= height; i++){
        int value = 1;
        for(int j = 1; j <= i; j++){
            cout << value << " ";
            value++;
        }
        cout << endl;
    }
    cout << endl;
}

void printRightAngeledCountTrianle(){
    int height = 4;
    int counter = 1;
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= i; j++){
            cout << counter << " ";
            counter++;
        }
        cout << endl;
    }
    cout << endl;
}

void printRightAngeledInvertedCountingTrianleJ(){
    int height = 4;
    for(int i = height; i >= 1; i--){
        for(int j = i; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void printRightAngeledInvertedCountingTrianle(){
    int height = 4;
    int value = (height * (height + 1))/2;
    for(int i = height; i >= 1; i--){
        for(int j = i; j >= 1; j--){
            cout << value << " ";
            value--;
        }
        cout << endl;
    }
    cout << endl;
}