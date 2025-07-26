#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr, int n){
    int minIndex = 0;
    for(int i = 0; i < n-1; i++){
        minIndex = i;
        for(int j  = i + 1; j < n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}


void bubbleSort(vector<int>&arr, int n){
    for(int i = 1; i < n; i++){
        bool swapped = false;
        for(int j = 0; j < n - i; j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void insertionSort(vector<int>&arr, int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        for(; j >= 0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            } else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void printArr(vector<int>&arr, int n){
    for(int i = 0; i <= n-1; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}


int main(){
    vector<int>arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    // selectionSort(arr, n);
    // cout << "Selection sort" << endl;
    // printArr(arr, n);
    // bubbleSort(arr, n);
    // cout << "Bubble sort" << endl;
    // printArr(arr, n);
    cout << "Unsorted array " ;
    printArr(arr, n);
    insertionSort(arr, n);
    cout << "Insetion sort" << endl;
    printArr(arr, n);

    return 0;
}