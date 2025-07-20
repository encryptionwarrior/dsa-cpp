#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;


void linearSearch();
void getMin();
void getMax();
void reverseArr();
void swapAlternates();
void findDuplicates();
void findInterSectionArr();
void pairSum();
void sortOne();
void findUnique();

int main(){
    // linearSearch();
    // getMin();
    // getMax();
    // reverseArr();
    // swapAlternates();
    // findDuplicates();
    // findInterSectionArr();
    // pairSum();
    // sortOne();
    findUnique();
    return 0;
}

void linearSearch(){
    int arr[5] = {20, 34, 56, 12, 45};
    bool isFind = false;
    int key = 12;
    for(int i = 0 ; i < 5 ; i++){
        if (arr[i] == key){
            isFind = true;
            break;
        }
    }

    if(isFind){
        cout << "Found the number : "<< key << endl;
    } else {
        cout << "Not Found the number :" << key << endl;
    }
}

void getMin(){
     int arr[5] = {20, 34, 56, 12, 45};
     int mini = INT_MAX;
     for(int i = 0; i < 5; i++){
        mini = min(mini, arr[i]);
        //  if (arr[i] < mini){
        //     mini = arr[i];
        // }
     }

     cout << "Minimum value is " << mini << endl;
}
void getMax(){
     int arr[5] = {20, 34, 56, 12, 45};
     int maxi = INT_MIN;
     for(int i = 0; i < 5; i++){
        // mini = max(mini, arr[i]);
         if (arr[i] > maxi){
            maxi = arr[i];
        }
     }

     cout << "Maximum value is " << maxi << endl;
}

void reverseArr(){
    int arr[5] = {20, 34, 56, 12, 45};
    int start = 0;
    int end = 4;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    cout << "Print Arr -> ";
    for(int i = 0; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swapAlternates(){
    int arr[5] = {20, 34, 56, 12, 45};
    for(int i = 0; i < 5; i+=2){
        if(i+1 < 5){
            swap(arr[i], arr[i+1]);
        }
    }

    cout << "Print Arr -> ";
    for(int i = 0; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findDuplicates(){
    vector<int> arr = {1, 3, 4, 2, 2};
     int ans = 0;
     for(int i = 0; i < arr.size(); i++){
        ans = ans^arr[i];
     }

     for(int i = 1; i < arr.size(); i++){
        ans = ans ^ i;
     }

     cout << "The duplicate number is :" << ans << endl;
}

void findInterSectionArr(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    int m = 5, n = 5;
    int i = 0, j = 0;
    vector<int>ans;

    while(i < n && j < m) {
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if(arr1[i] < arr2[j]){
            i++;
        } else {
            j++;
        }
    }

    cout << "Intersection Arr is :";
    for(int i = 0; i < ans.size(); i++){
        cout  << ans[i] << " ";
    }
}

void pairSum(){
   vector<int> arr = {1, 3, 2, 2, 3, 1};
int s = 4;
vector<vector<int>> ans;
for(int i = 0; i < arr.size(); i++){
    for(int j = i + 1; j < arr.size(); j++){
        if(arr[i] + arr[j] == s){
            vector<int> temp;
            temp.push_back(min(arr[i], arr[j]));
            temp.push_back(max(arr[i], arr[j]));
            ans.push_back(temp);
        }
    }
}

sort(ans.begin(), ans.end());

for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
        cout << ans[i][j] << " ";

    }
    cout <<  endl;
}
}

void sortOne(){
    int arr[6] = {0, 1, 0, 1, 0, 1};
    int n = 6;
    int left = 0, right = n - 1;
    while(left < right){
        while(arr[left] == 0 && left < right){
            left++;
        }
        while(arr[right] == 1 && left < right){
            right--;
        }
        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
}

void findUnique(){
    int arr[] = {2, 3, 5, 4, 5, 3, 2};
int size = 7;
int ans = 0;
for(int i = 0; i < size; i++){
    ans  = ans^arr[i];
}

cout << "Unique element is : " << ans << endl;

}