#include<iostream>
#include<vector>
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

    vector<int> arr = {90, 30, 20, 120, 50, 60, 40, 150};

    cout << "Before building Min Heap : ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = buildMinHeap(arr);

       cout << "After building Min Heap : ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}