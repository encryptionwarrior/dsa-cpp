#include<iostream>
#include<vector>
using namespace std;

void reverseStr(string&str, int i, int j){
    if(i > j){
        return ;
    }
        swap(str[i], str[j]);

        i++;
        j--;
    reverseStr(str, i, j);
}

bool checkPalindrome(string str, int i, int j){
    if(i > j){
        return false;
    }

    if(str[i] != str[j]){
        return false;
    }

    checkPalindrome(str, i + 1, j - 1);
}

int calculatePower(int a, int b){
    if(b == 0){
        return 1;
    }
    int halfPower = calculatePower(a, b/2);
    if(b % 2 == 0){
        return halfPower * halfPower;
    } else {
        return a * halfPower * halfPower;
    }
}


void bubbleSort(int *arr, int n){
    if(n == 0 || n == 1){
        return;
    } 

    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, n - 1);

}

void selectionSort(vector<int>&arr, int start){
    if(start >= arr.size()-1){
        return;
    }

    int minIndex = start;

    for(int i = start; i < arr.size(); i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }

    swap(arr[start], arr[minIndex]);

    selectionSort(arr, start + 1);

}

void insertionSort(vector<int>&arr, int limit){
    if(limit >= arr.size()){
        return;
    }

    int j = limit - 1;
    int temp = arr[limit];

    while(j >= 0 && arr[j] > temp){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = temp;

    insertionSort(arr, limit + 1);
}

void printArr(int *arr, int n){
    cout << "Print Arr " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i]  << ", ";
    }
    cout << endl;
}
void printArr2(vector<int>arr, int n){
    cout << "Print Arr " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i]  << ", ";
    }
    cout << endl;
}

int main(){

    string str = "abcde";
    reverseStr(str, 0, str.length() - 1);
    cout << "Print the string: => " << str << endl;

    string str2 = "madama";
    bool isPalindrome = checkPalindrome(str2, 0, str2.length() - 1);
    if(isPalindrome){
        cout << "This is palidrome string: => " << str2 << endl;
    } else {
        cout << "This is not a palidrome string: => " << str2 << endl;
    }

    int pow = calculatePower(5, 5);
    cout << "Power of 2^ 5 is => " << pow << endl; 


     int arr[] = {5, 3, 8, 4, 2};
     int size = sizeof(arr) /sizeof(arr[0]);
     bubbleSort(arr, size);
printArr(arr, size);

vector<int> arr2 = {5, 3, 8, 4, 2};
selectionSort(arr2, 0);
printArr2(arr2, arr2.size());


insertionSort(arr2, 1);
printArr2(arr2, arr2.size());


    return 0;
}