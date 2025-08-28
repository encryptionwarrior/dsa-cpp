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

class Node {
    public:
        int data;
        int row;
        int col;

    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
    public:
        bool operator () (Node* a, Node* b){
            return a->data > b->data;
        }
};

vector<int> mergeSortedArrays(vector<vector<int>> kArrays, int k){
    priority_queue<Node* , vector<Node*>, compare> minHeap;

    for(int row = 0; row < k; row++){
        Node* temp = new Node(kArrays[row][0], row, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(minHeap.size() > 0){
        Node* temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if(col + 1 > kArrays[row].size()){
            Node* next = new Node(kArrays[row][col+1], row, col + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

void fnMergeKSortedArr(){
    vector<vector<int>> kArrays;
    int k;
    cout << "Enter the value of k (number of arrays) :  ";
    cin >> k;

    for(int i = 0; i < k; i++){
        vector<int> curr;
        cout << "Enter the elements of array " << i + 1 << " (enter - to stop) : ";
        int temp_input;
        cin >> temp_input;

        do {
            if(temp_input != -1){
                curr.push_back(temp_input);
            }
            cin >> temp_input;
        } while(temp_input != -1);
        kArrays.push_back(curr);
    }

    vector<int> mergedArray = mergeSortedArrays(kArrays, k);

    cout << "Merged array : ";
    for(auto i : mergedArray){
        cout << i << " ";
    }

    cout << endl;
}

int main(){
    // findKthLarhestSum();
    fnMergeKSortedArr();
    return 0;
}