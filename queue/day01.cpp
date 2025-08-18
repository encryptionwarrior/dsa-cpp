#include<iostream>
#include<queue>
#include<deque>
using namespace std;

void queueBasic(){
    queue<int> q;

    q.push(11);

    cout << "Front element of q: " << q.front() << endl;
    cout << "Back element of q: " << q.back() << endl;

    q.push(15);

    cout << "Front element of q: " << q.front() << endl;
    cout << "Back element of q: " << q.back() << endl;
    
    q.push(23);
    q.push(30);

    cout << "Size of queue : " << q.size() << endl;

      cout << "Front after pop : " << q.front() << endl;
    cout << "Back after pop : " << q.back() << endl;

    q.pop();
    q.pop();

    cout << "Size of queue : " << q.size() << endl;

    q.pop();

    if(q.empty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
}

class Queue {
    int *arr;
    int size;
    int front;
    int rear;

    public:
        Queue(int s){
            size = s;
            arr = new int[size];
            front = 0;
            rear = 0;
        }
    
    void push(int val){
        if(rear == size){
            cout << "Queue overflow!" << endl;
        } else {
            arr[rear] = val;
            rear++;
        }
    }

    void pop(){
        if(front == rear){
            cout << "Queue underflow!" <<endl;
        } else {
            front++;

            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int frontElement(){
        return (front == rear) ? -1 : arr[front];
    }

    int backElement(){
        return (front == rear) ? -1 : arr[rear  - 1];
    }

    int queueSize(){
        return (rear - front);
    }

    bool empty(){
        return (front == rear) ? true : false;
    }

    ~Queue(){
        delete[] arr;
    } 
};

void manualQueue(){
    Queue q = 5;

    q.push(11);

    cout << "Front element of q: " << q.frontElement() << endl;
    cout << "Back element of q: " << q.backElement() << endl;

    q.push(15);

        cout << "Front element of q: " << q.frontElement() << endl;
    cout << "Back element of q: " << q.backElement() << endl;

    q.push(23);
    q.push(30);
    q.push(40);

    cout << "Size of queue : " << q.queueSize() << endl;

    q.push(50);

    cout << "Front before pop : " << q.frontElement() << endl;
    cout << "Back before pop : " << q.backElement() << endl;

    q.pop();
      cout << "Front after pop : " << q.frontElement() << endl;
    cout << "Back after pop : " << q.backElement() << endl;

    q.pop();
    q.pop();

    cout << "Sixe of queue : " << q.queueSize() << endl;

    if(q.empty()){
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }
}

class CQueue {
    int *arr;
    int size;
    int front;
    int rear;

    public: 
        CQueue(int s){
            size = s;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

    void push(int val){
        if((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)){
            cout << "CQueue overflow!" << endl;
            return;
        } else if(front == -1){
            front = rear = 0;
        } else if(rear == size - 1){
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = val;
    }

    void pop(){
        if(front == -1 || (front == rear + 1 && front != (rear + 1 + size)%size)){
            cout << "CQueue underflow!" << endl;
            return;
        } else if(front == rear){
            front = -1;
            rear = -1;
        } else if(front == size - 1){
            front = 0;
        } else {
            front++;
        }
    }

    int frontElement(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }

    int backElelment(){
        if(rear == -1){
            return -1;
        }

        return arr[rear];
    }

    int queueSize(){
        if(front == -1) return 0;

        if(rear >= front){
            return rear - front + 1;
        } else {
            return (size - front) + (rear + 1);
        }
    }

    bool empty(){
        return (front == -1);
    }

    ~CQueue(){
        delete[] arr;
    }
};

void CircularQueue(){
    CQueue q(5);

    q.push(11);

    cout << "Front element of q: " << q.frontElement() << endl;
    cout << "Back element of q: " << q.backElelment() << endl;
    q.push(15);

    cout << "Front element of q: " << q.frontElement() << endl;
    cout << "Back element of q: " << q.backElelment() << endl;
    
    q.push(23);
    q.push(30);

    cout << "Size of queue : " << q.queueSize() << endl;
    
    q.push(40);
    cout << "Size of queue : " << q.queueSize() << endl;

    q.push(50);

    cout << "Front before pop : " << q.frontElement() << endl;
    cout << "Back before pop : " << q.backElelment() << endl;

    q.pop();
       cout << "Front after  pop : " << q.frontElement() << endl;
    cout << "Back after pop : " << q.backElelment() << endl;

    q.push(50);
    cout << "Front element of q: " << q.frontElement() << endl;
    cout << "Back element of q: " << q.backElelment() << endl;
    cout << "Size of queue : " << q.queueSize() << endl;

    q.pop();
    q.pop();
    q.pop();
    
    cout << "Size of queue : " << q.queueSize() << endl;
        cout << "Front element of q: " << q.frontElement() << endl;
    cout << "Back element of q: " << q.backElelment() << endl;


    q.pop();
    
    cout << "Front element of q: " << q.frontElement() << endl;
    cout << "Back element of q: " << q.backElelment() << endl;
    cout << "Size of queue : " << q.queueSize() << endl;
    
    q.pop();
    if(q.empty()){
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    q.pop();

}

void doublyEndedQueue(){
    deque<int> q;
    q.push_front(11);
    q.push_back(14);

    cout << "Front element of q: " << q.front() << endl;
    cout << "Back element of q: " << q.back() << endl;
}

int main(){
    // queueBasic();
    // manualQueue();
    // CircularQueue();
    doublyEndedQueue();
    return 0;
}