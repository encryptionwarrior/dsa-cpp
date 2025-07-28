#include<iostream>
using namespace std;

void Pointers(){
    int arr[] = {10, 20, 30};
    int *ptr = arr;
    ptr++;
    cout << "Check pointer p++ "<< arr[*ptr] << endl;

    int *ptr1 =  NULL;

    int a = 10;
    int *p1 = &a;
    int **p2 = &p1;

    cout << "check *p1 "<< *p1 << endl;
    cout << "check **p1 "<< **p2 << endl;

    int *arr2 = new int[5];
    delete arr;

    void *ptr3;
    int a1 = 10;
    ptr3 = &a1;
    int *intPtr = (int*)ptr3;

    cout << "Void ptr " << *intPtr << endl;

}

int main(){
    int a = 5;
    int *ptr = &a;
    int value = *ptr;

    cout << "check p " << ptr << endl;
    cout << "check *p " << *ptr << endl;
    cout << "check value " << value << endl;
    Pointers();
    return 0;
}