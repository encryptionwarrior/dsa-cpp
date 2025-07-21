#include<iostream>
#include<vector>
using namespace std;

void firstLastPosition();


int main(){
    firstLastPosition();
    return 0;
}


int firstOcc(vector<int> &arr, int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        } else if(arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int lastOcc(vector<int> &arr, int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(arr[mid] == key) {
            ans = mid;
            s = mid + 1; 
        } else if(arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

void firstLastPosition() {
    vector<int> arr = {1, 2, 3, 3, 3, 5, 6};
    int n = arr.size();
    pair<int, int> p;
    p.first = firstOcc(arr, n, 3);
    p.second = lastOcc(arr, n, 3);

    cout << "First occurrence is " << p.first << endl;
    cout << "Last occurrence is " << p.second << endl;
}