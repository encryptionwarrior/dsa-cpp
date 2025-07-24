#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int>arr){
    int count = 0;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < arr[i-1]){
                count++;
        } 
    }

    if(arr[arr.size()-1] > arr[0]){
        count++;
    }

    return count <= 1;
}

int main(){
    vector<int> arr =  {3, 4, 5, 1, 2};
    bool isSorted = checkSorted(arr);
    cout << "check rotated sorted array => " << isSorted << endl;
    return 0;
}