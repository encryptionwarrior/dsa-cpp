#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthLargestSumOfSubArrays(vector<int>arr, int k){
    priority_queue<int, vector<int>, greater<int>> sumStore;

    int size = arr.size();

    for(int i = 0; i < size; i++){
        int temp_sum = 0;
        for(int j = i; j < size; j++){
            temp_sum += arr[j];

            if(sumStore.size() < k){
                sumStore.push(temp_sum);
            } else {
                if(temp_sum > sumStore.top()){
                    sumStore.pop();
                    sumStore.push(temp_sum);
                }
            }
        }
    }

    return sumStore.top();
}

void findKthLarhestSum(){
    vector<int> arr;
    cout << "Enter the elements of array (enter -1 to stop) : ";
    int temp_input;
    cin >> temp_input;

    do
    {
        arr.push_back(temp_input);
        cin >> temp_input;
    } while (temp_input != -1);

    int k;
    cout << "Enter the value of K : ";
    cin >> k;

    if(k <= 0 || k > (long long)arr.size() * (arr.size() + 1)/2){
              cout << "Invalid K value. Please enter a positive K within bounds of total subarray sums." << endl;
        return;
    }

    int largestSum = kthLargestSumOfSubArrays(arr, k);

    cout << "The kth largest sum of subarrays : " << largestSum << endl;
}

int main(){
    findKthLarhestSum();
    return 0;
}