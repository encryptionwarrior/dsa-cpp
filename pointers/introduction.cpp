#include <iostream>
using namespace std;

void Pointers()
{
    int arr[] = {10, 20, 30};
    int *ptr = arr;
    ptr++;
    cout << "Check pointer p++ " << arr[*ptr] << endl;

    int *ptr1 = NULL;

    int a = 10;
    int *p1 = &a;
    int **p2 = &p1;

    cout << "check *p1 " << *p1 << endl;
    cout << "check **p1 " << **p2 << endl;

    int *arr2 = new int[5];
    delete arr;

    void *ptr3;
    int a1 = 10;
    ptr3 = &a1;
    int *intPtr = (int *)ptr3;

    cout << "Void ptr " << *intPtr << endl;
}


void example1(){
    int a = 10;
    int *ptr = &a;
    cout << "Address of a: " << ptr << endl;
    cout << "Value of a: " << *ptr << endl;
    *ptr = 20;
    cout << "Value of a: " << a << endl;

}

void garbageExample(){
    // int *ptr = 0;
    // cout << *ptr << endl;
    // int i = 5;
    // int *q = &i;
    // cout << q << endl;
    // cout << *q << endl;
    // int *p = 0;
    // p = &i;

    // cout << p << endl;
    // cout << *p << endl;

    int num = 5;
    int a = num;

    cout << "a before " << num << endl;
    a++;
    cout << "a after " << num << endl;

    int *p = &num;
    cout << "p before " << num << endl;
    (*p)++;
    cout << "p after " << num << endl;

    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    int i = 3;
    int *t = &i;
    *t = *t + 1;
    cout << *t << endl;
    cout << " before t " << t << endl;
    t = t + 1;
    cout << " after t " << t << endl;
}

void example2(){
    int num = 5;
    cout << " address of num is " << &num << endl;
    int *ptr = &num;
    cout << "Address is : " << ptr << endl;
    cout << "Value is : " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d;

    cout << "Address is : " << p2 << endl;
    cout << "Value is : " << *p2 << endl;

    cout << " size of integer is " << sizeof(num) << endl;
    cout << " size of pointer is " << sizeof(ptr) << endl;
    cout << " size of pointer is " << sizeof(p2) << endl;
}


int main()
{
    // int a = 5;
    // int *ptr = &a;
    // int value = *ptr;

    // cout << "check p " << ptr << endl;
    // cout << "check *p " << *ptr << endl;
    // cout << "check value " << value << endl;
    // Pointers();
    // example1();
    // garbageExample();
    example2();
    return 0;
}