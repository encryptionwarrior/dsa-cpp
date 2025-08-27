#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Heap {
    public:
        int arr[100];
        int size;

        Heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size++;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index / 2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }
        }

        void deleteheap(){
            if(size == 0){
                cout << "Heap is empty!" << endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i <= size){
                int leftChild = 2 * i;
                int rightChild = (2 * i) + 1;
                int largest = i;

                if(leftChild <= size && arr[largest] < arr[leftChild]){
                    largest = leftChild;
                }
                if(leftChild <= size && arr[largest] < arr[rightChild]){
                    largest = rightChild;
                }

                if(largest == i){
                    return;
                } else {
                    swap(arr[i], arr[largest]);
                    i = largest;
                }
            }
        }

        void print(){
            cout << "Max heap : ";
            for(int i = 1; i <= size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 3 * i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(left <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n , largest);
    }
}


void heapifyMin(vector<int>& arr, int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left <= n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(left <= n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n , smallest);
    }
}

vector<int> buildMinHeap(vector<int>& arr){
    int n = arr.size();

    for(int i = (n/2) - 1; i >= 0; i--){
        heapifyMin(arr, n, i);
    }

    return arr;
}

void heapSort(int arr[], int size){
    while(size > 1){
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

void maxHeapPriorityQueue(){
    priority_queue<int> maxHeap;

    maxHeap.push(52);
    maxHeap.push(50);
    maxHeap.push(54);
    maxHeap.push(40);
    maxHeap.push(35);
    maxHeap.push(65);

    cout << "Top element : " << maxHeap.top() << endl;

    maxHeap.pop();
    cout << "Top element : " << maxHeap.top() << endl;
    
    maxHeap.pop();
    maxHeap.pop();
    cout << "Top element : " << maxHeap.top() << endl;

    if(maxHeap.empty()){
        cout << "Max heap is empty!" << endl;
    } else {
        cout << "Max heap is not empty! current size:" << maxHeap.size() << endl;
    }

    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
 
    if(maxHeap.empty()){
        cout << "Max heap is now empty after popping all elements !" << endl;
    }

};


void minHeapPriorityQueue(){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(52);
    minHeap.push(50);
    minHeap.push(54);
    minHeap.push(40);
    minHeap.push(35);
    minHeap.push(65);

    cout << "Top element : " << minHeap.top() << endl;

    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;
    
    minHeap.pop();
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;

    if(minHeap.empty()){
        cout << "Min heap is empty!" << endl;
    } else {
        cout << "Min heap is not empty! current size:" << minHeap.size() << endl;
    }

    minHeap.pop();
    minHeap.pop();
    minHeap.pop();
 
    if(minHeap.empty()){
        cout << "Min heap is now empty after popping all elements !" << endl;
    }

};

int main(){

    // Heap h;

    // cout << "Inserting elements into heap : " << endl;

    // h.insert(50);
    // h.insert(40);
    // h.insert(60);
    // h.insert(30);
    // h.insert(55);
    // h.insert(70);
    // h.insert(20);
    // h.print();

    // cout << "Deleting root from heap: " << endl;
    // h.deleteheap();
    // h.print();

    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n = 5;

    // cout << "\nBuilding Heap from array using heapify:" << endl;
    // cout << "Original array: ";

    // for(int i = 1; i <= n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // for(int i = n/2; i > 0; i--){
    //     heapify(arr, n, i);
    // }

    // cout << "Heapify array : ";

    // for(int i = 1;  i <= n; i++){
    //     cout << arr[i] << " ";
    // }

    // cout << endl;

    // vector<int> arr = {90, 30, 20, 120, 50, 60, 40, 150};

    // cout << "Before building Min Heap : ";
    // for(int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // arr = buildMinHeap(arr);

    //    cout << "After building Min Heap : ";
    // for(int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // int arr[6] = {-1, 54, 53, 55, 50, 52};
    // int size = 5;

    // cout << "Before building Min Heap : ";
    // for(int i = size/2; i > 0; i--){
    //   heapify(arr, size, 1);
    // }

    //   cout << "Unsroted Array after max heap creation : ";
    // for(int i = 0; i < size; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // heapSort(arr, size);

    //    cout << "Sorted array (Heap Sort) : ";
    // for(int i = 0; i < size; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    maxHeapPriorityQueue();
    minHeapPriorityQueue();

    return 0;
}