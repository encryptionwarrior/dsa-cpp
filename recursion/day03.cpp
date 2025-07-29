#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    if(n == 0 || n == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }

    bool remainingPart = isSorted(arr + 1, n - 1);
    return remainingPart;
}

int getSum(int *arr, int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return arr[0];
    }

    int remainingPart = getSum(arr+1, n - 1);
    int sum = arr[0] + remainingPart;

    return sum;
}

bool linearSearch(int arr[], int size, int k){
    if(size == 0){
        return false;
    }

    if(arr[0] == k){
        return true;
    } else {
        bool remainingPart = linearSearch(arr + 1, size - 1, k);
        return remainingPart;
    }

}

bool binarySearch(int *arr, int s, int e, int k){
    if(s < e){
        return false;
    }

    int mid = s + (e - s)/2;
    if(arr[mid] == k){
        return true;
    }

    if(arr[mid] < k){
        return binarySearch(arr, mid + 1, e, k);
    } else {
        return binarySearch(arr, s, mid + 1, k);
        
    }

}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    bool checkSorted = isSorted(arr, 5);
    cout << "Is array sorted? " << checkSorted << endl;

    int sum = getSum(arr, 5);
    cout << "Get sum of arr => " << sum << endl;

    if(linearSearch(arr, 5, 8)){
        cout << "Element found" << endl;
    } else {
        cout << "Element not found " << endl;
    }
    if(binarySearch(arr, 0, 4, 16)){
        cout << "Element found binary" << endl;
    } else {
        cout << "Element not found binary " << endl;
    }

    return 0;
}