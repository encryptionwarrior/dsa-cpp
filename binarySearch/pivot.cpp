#include<iostream>
#include<vector>
using namespace std;

int find_pivot(vector<int> & arr);
int get_pivot(vector<int> & arr);

int main(){
    // vector<int> arr = {0, 2, 4, 6, 3, 1};
    vector<int> arr =  {1, 3, 8, 10, 17};
    // int pivot = find_pivot(arr);
    int pivot2 = get_pivot(arr);
    // cout << "Here is the pivot "<< pivot << endl;
    cout << "Here is the pivot index "<< pivot2 << endl;
    return 0;
}

int find_pivot(vector<int> & arr){
    int s = 0, e = arr.size() - 1;
    int mid = (e+s)/2;

    while(s < e){
        if(arr[mid] < arr[mid + 1]){
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = (e+s)/2;
    }

    return s;

}

int get_pivot(vector<int> & arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s)/2;
    while (s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return s;
}