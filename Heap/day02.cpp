#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthSmallest(vector<int> arr, int k){
    priority_queue<int> Heap;

    for(int i = 0; i < k; i++){
        Heap.push(arr[i]);
    }

    for(int i = k; i < arr.size(); i++){
        if(arr[i] < Heap.top()){
            Heap.pop();
            Heap.push(arr[i]);
        }
    }

    return Heap.top();

}

void kthSmallestFunction(){
      vector<int> arr;
    cout << "Enter the elements of array (enter -1 to stop) : ";
    int temp;
    cin >> temp;

    while(temp != -1){
        arr.push_back(temp);
        cin >> temp;
    }

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    if(k <= 0 || k > arr.size()){
        cout << "Invalid k value. K must be between 1 and " << arr.size() << endl;
        return ;
    }

    int answer = kthSmallest(arr, k);

    cout << "Kth smallest element : " << answer << endl;
}


int kthLargest(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int>> Heap;

    for(int i = 0; i < k; i++){
        Heap.push(arr[i]);
    }

    for(int i = k; i < arr.size(); i++){
        Heap.pop();
        Heap.push(arr[i]);
    }

    return Heap.top();
};

void kthLargestFunc(){
     vector<int> arr;
    cout << "Enter the elements of array (enter -1 to stop) : ";
    int temp;
    cin >> temp;

    while(temp != -1){
        arr.push_back(temp);
        cin >> temp;
    }

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    if(k <= 0 || k > arr.size()){
        cout << "Invalid k value. K must be between 1 and " << arr.size() << endl;
        return ;
    }

    int answer = kthLargest(arr, k);

    cout << "Kth Largest element : " << answer << endl;
}

int main(){

//   kthSmallestFunction();
  kthLargestFunc();

    return 0;
}