#include <iostream>
using namespace std;
#include <algorithm>

void SearchingEl();
void reverseEl();
void sumArr();
void exampleCode();
int main(){
    // SearchingEl();
    // reverseEl();
    // sumArr();
    exampleCode();
    return 0;
}

void IntroArr(){
 int arr[5] = {70, 33, 54, 65, 84};
    int arr2[5] = {};
    cout << arr[0] << endl;
    cout << arr[4] << endl;

    cout << "Counting numbers ++ ";
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Matrics " << matrix[1][2] << endl;

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Size of arr " << size << endl;
    sort(arr, arr+5);
    cout << "Sorting arr " << arr  << endl;
}

void SearchingEl(){
    int arr[5] = {30, 10, 20, 45, 34};
    int key = 54;
    bool found = false;
    for(int i = 1; i < 5; i++){
        if(arr[i] == key){
            found = true;
            break;
        }
    }

    if(found){
        cout << "Found the element" << endl;
    } else {
        cout << "Not Found the element" << endl;
    }
}

void voidPrintArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseEl(){
     int arr[5] = {30, 10, 20, 45, 34};
     reverse(arr, arr+5);
     voidPrintArr(arr, 5);
}

void sumArr(){
     int arr[5] = {30, 10, 20, 45, 34};
     int sum = 0;
     for(int i = 0; i < 5; i++){
        sum += arr[i];
     }

     cout << "Sum of Arr " << sum << endl;
}

void exampleCode(){
    int number[15];

    cout << "Value at 14 index " << number[14] << endl;
    
    int second[3] = {5, 7, 11};
    cout << "Value at 2 index " << number[2] << endl;

    int third[15] = {2, 7};
    int n = 15;

    int thirdSize = sizeof(third)/sizeof(int);
    cout << "Size of Third is " << thirdSize << endl;

    char ch[5] = {'a', 'b', 'c', 'r', 'p'};
    cout << ch[3] << endl;

    cout << " Printing the array " << endl;

    for(int i = 0; i < 5; i++){
        cout << ch[i] << " ";
    }

    cout << " Printing Done " << endl;
    double firstDouble[5];
    float firstFloat[6];
    bool firstBool[9];

    cout << endl << " Everything is Fine " << endl << endl;

}