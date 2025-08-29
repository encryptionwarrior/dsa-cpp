#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
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

class List {
    public:
        int data;
        List* next;

        List(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insert(List* &head, List* &tail, int val){
    List* temp = new List(val);
    if(head == NULL){
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

class compare2 {
    public:
        bool operator () (List* a, List* b){
            return a->data > b->data;
        }
};

List* mergeSortedLists(vector<List*> kLists){
    priority_queue<List*, vector<List*>, compare2> minHeap;
    int k = kLists.size();

    if(k == 0){
        return NULL;
    }

    for(int i = 0; i < k; i++){
        if(kLists[i] != NULL){
            minHeap.push(kLists[i]);
        }
    }

    List* head = NULL;
    List* tail = NULL;

    while(minHeap.size() > 0){
        List* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
            head = tail = top;
        } else {
            tail->next = top;
            tail = top;
        }

        tail->next = NULL;
    }

    return head;
}

void fnMergeKOsrtedList(){
    vector<List*> kLists;
    int k;

    cout << "Enter the value of k (number of lists) : ";
    cin >> k;

    for(int i = 0; i < k; i++){
        List* head = NULL;
        List* tail = NULL;

        cout << "Enter the value for list " << i + 1 << " (-1 to stop) :  ";

        int val;
        cin >> val;

        do {
            if(val != -1){
                insert(head, tail, val);
            }
            cin >> val;
        } while(val != -1);
        kLists.push_back(head);
    }

    List* mergedHead = mergeSortedLists(kLists);

    List* temp_ptr = mergedHead;
    cout << "Merged List : ";

    while(temp_ptr != NULL){
        cout << temp_ptr->data << " ";
        temp_ptr = temp_ptr->next;
    }
    cout << endl;
}

class Node2 {
    public: 
        int data;
        int row;
        int col;
    
    Node2(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};


class compare3 {
    public: 
        bool operator () (Node* a, Node *b){
            return a->data > b->data;
        }
};

int smallestRange(vector<vector<int>> kArrays, int k, int n){
    priority_queue<Node*, vector<Node*>, compare3> minHeap;
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int row = 0; row < k; row++){
        int element = kArrays[row][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, row, 0));

    }

    int start = mini;
    int end = maxi;

    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(temp->col + 1 < kArrays[temp->row].size()){
            int nextElement = kArrays[temp->row][temp->col+1];
            maxi = max(maxi, nextElement);
            minHeap.push(new Node(nextElement, temp->row, temp->col + 1));
        } else {
            break;
        }
    }

    return (end - start) + 1;
}

void smallestRangeKList(){
    vector<vector<int>> kArrays;
    int K;
    int N;

    cout << "Enter the value of K (number of Arrays) : ";
    cin >> K;


    cout << "Enter the size of each array (assuming all arrays have this size ) : ";
    cin >> N;

    for(int i = 0; i < K; i++){
        vector<int> curr(N);

        cout << "Enter the " << N << " elements of array " << i + 1 << " (must be sorted) : ";

        for(int j = 0; j < N; j++){
            cin >> curr[N];
        }

        kArrays.push_back(curr);
    }

    int range = smallestRange(kArrays, K, N);

    cout << "Smallest range in the given sorted lists : " << range << endl;


}


int signum(int a, int b){
    return (a == b) ? 0 : (a > b ? 1 : -1);
}

void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median){
    switch(signum(maxHeap.size(), minHeap.size())){
        case 0:
            if(element > median){
                minHeap.push(element);
                median = minHeap.top();
            } else {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;

            case 1:
                if(element > median){
                    minHeap.push(element);
                } else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                }

                median = (minHeap.top() + maxHeap.top())/2;
                break;


            case -1:
                if(element > median){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                } else {
                    minHeap.push(maxHeap.top());
                       minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                }

                median = (minHeap.top() + maxHeap.top())/2;
                break;
    }
}

vector<int> findMedian(vector<int>&arr, int N){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;

    for(int i = 0; i < N; i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

void fnFindMedian(){
    int N;
    cout << "Enter the size of the array : ";
    cin >> N;
    vector<int> arr(N);

    cout << "Enter the elements of array : ";
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    vector<int> ans = findMedian(arr, N);

    cout << "Median of the stream (final median) : " << ans[ans.size() - 1] << endl;
}

int main(){
    // findKthLarhestSum();
    // fnMergeKSortedArr();
    // fnMergeKOsrtedList();
    // smallestRangeKList();
    fnFindMedian();
    return 0;
}