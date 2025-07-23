#include <iostream>
#include <vector>
using namespace std;

int get_pivot(vector<int>&arr, int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int binarySearch(vector<int>&arr, int s, int e, int key){
        int start = s;
        int end = e;
        int mid = start + (end - start)/2;

        while(start <= end){
            if(arr[mid] == key){
                return mid;
            } else if(key > arr[mid]){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return -1;
}


int main(){
    vector<int> arr =  {7, 9, 1, 2, 3};
    int key = 2;
    int n = arr.size();
    int ans = 0;

    int pivot = get_pivot(arr, n);
    if(key >= arr[pivot] && key <= arr[n-1]){
        ans =  binarySearch(arr, pivot, n-1, key);
    } else {
        ans = binarySearch(arr, 0, pivot - 1, key);
    }

    cout << "Element at postion of key 2 is => " << ans << ", " << pivot << endl;

    return 0;
}




