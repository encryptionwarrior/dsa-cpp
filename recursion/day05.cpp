#include<iostream>
#include<vector>
using namespace std;

long long merge(vector<long long>&arr, int s, int e){
    int mid = s + (e - s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<long long> left(len1);
    vector<long long> right(len2);

    for(int i = 0; i < len1; i++){
        left[i] = arr[s+i];
    }

    for(int i = 0; i < len2; i++){
        right[i] = arr[mid + 1 + i];
    }

    long long inversions = 0;
    int i = 0, j = 0, k = s;

    while(i < len1 && j < len2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = left[j++];
            inversions += (len1 - i);

        }
    }

    while(i < len1){
        arr[k++] = left[i++];
    }
    while(i < len2){
        arr[k++] = left[j++];
    }

    return inversions;

}

long long mergerSort(vector<long long>&arr, int s, int e){
    if(s >= e) return 0;

    int mid = s + (e - s)/2;
    long long inversions = 0;
    inversions += mergerSort(arr, s, mid);
    inversions += mergerSort(arr, mid + 1, e);
    inversions += merge(arr, s, e);
    return inversions;
}

long long inversionCount(vector<long long> &arr){
    return mergerSort(arr, 0, arr.size() - 1);
}


void merge2(int *arr, int s, int e){
    int mid = (s + e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;


    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++){
        first[i] = arr[mainArrayIndex++];
    }


    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];

        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete first;
    delete second;

}

void mergeSort2(int *arr, int s, int e){
    if(s >= e){
        return;
    }

    int mid = (s + e)/2;

    mergeSort2(arr, s, mid);
    mergeSort2(arr, mid + 1, e);

    merge2(arr, s, e);
}

int main(){
    vector<long long> arr = {8, 4, 2, 1};
    int n = 4;

    long long result = inversionCount(arr);
    cout << "Total Inversions: " << result << endl;

    int arr2[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12}; // Sample array
    int n2 = 15; 

    mergeSort2(arr2, 0, n2-1);

    cout << "Srot by meger +++ => ";

    for(int i = 0; i < n2; i++){
        cout << arr2[i] << " ";
    }

    return 0;
}