#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout << "Enter the data (-1 for NULL) : ";
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the LEFT Child of " << data << " : ";
    root->left = buildTree(root->left);


    cout << "Enter the RIGHT Child of " << data << " : ";
    root->right = buildTree(root->right);

    return root;

}


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


int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->left);

    return left + right + 1;
};

bool isCBT(Node* root, int index, int cnt){
    if(root == NULL){
        return true;
    }

    if(index >= cnt){
        return false;
    }

    bool left = isCBT(root->left, 2 * index + 1, cnt);
    bool right = isCBT(root->right, 2 * index + 2, cnt);

    return left && right;
}

bool isMaxOrder(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }

    if(root->right == NULL){
        return (root->data) > (root->left->data);
    }

    bool leftOrder = isMaxOrder(root->left);
    bool rightOrder = isMaxOrder(root->right);

    bool currOrder = (root->data > root->left->data) && (root->data > root->right->data);

    return leftOrder && rightOrder && currOrder;
}

bool isMinOrder(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }

    if(root->right == NULL){
        return (root->data) < (root->left->data);
    }

    bool leftOrder = isMinOrder(root->left);
    bool rightOrder = isMinOrder(root->right);

    bool currOrder = (root->data < root->left->data) && (root->data < root->right->data);

    return leftOrder && rightOrder && currOrder;
}

bool checkMaxHeap(Node* root){
    int nodeCount = countNodes(root);
    return isCBT(root, 0, nodeCount) && isMinOrder(root);
}

void isBinaryTreeHeap(){
    Node* root = NULL;
    cout << "Enter data to create a binary tree (use -1 for NULL children) : ";
    root = buildTree(root);

    bool isMaxHeapOrder = checkMaxHeap(root);
    bool isMinHeapOrder = checkMaxHeap(root);

    if(isMaxHeapOrder){
        cout << "Given Binary Tree is a Max Heap!" << endl;
    } else if(isMinHeapOrder){
        cout << "Given binary Tree is a min  heap!" << endl;
    } else {
        cout << "Given Binary tree is not a heap!" << endl;
    }
}

void heapify(vector<int>&arr, int index, int size){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;


    if(left < size && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != index){
        swap(arr[index], arr[largest]);
        heapify(arr, largest, size);
    }
}

vector<int> mergeHeaps(vector<int> arr1, vector<int> arr2){
    for(auto i : arr2){
        arr1.push_back(i);
    }

    for(int i = arr1.size() / 2 - 1; i >= 0; i--){
        heapify(arr1, i, arr1.size());
    }

    return arr1;
}

void merge2Maxheap(){
    vector<int> arr1, arr2;

    cout << "Enter the elements of first array (enter -1 to stop) : ";
    int temp;
    cin >> temp;

    while(temp != -1){
        arr1.push_back(temp);
        cin >> temp;
    }


    cout << "Enter the elements of second array (enter -1 to stop) : ";
    cin >> temp;

    while(temp != -1){
        arr1.push_back(temp);
        cin >> temp;
    }

    vector<int> result = mergeHeaps(arr1, arr2);

    cout << "Merged heaps : ";

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    cout << endl;
}

int main(){

//   kthSmallestFunction();
//   kthLargestFunc();
//   isBinaryTreeHeap();
merge2Maxheap();

    return 0;
}