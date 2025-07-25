#include<iostream>
using namespace std;




int main(){
    char arr[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char name[] = "John";

    char str[] = "World";
    str[0] = 'w';
    cout << str << endl;;

    string str1 = "Hello";
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + " " + s2; 
    cout << s1[0] << endl;

    char arr1[] = "Hello";
    cout << strlen(arr1) << endl;

    char src[] = "copy";
    char dest[10];
    cout << strcpy(dest, src) << endl;


    char t1[] = "abc";
    char t2[] = "def";
    char dest[10];
    int result = strcmp(t1, t2);
    cout << strcpy(dest, src) << endl;

    string str3 = "Hello";
    cout << str3.length() << endl;
    cout << str3.substr(1, 3) << endl;
    cout << str3.find("world") << endl;


    char arr3[] = "Hello";
    string str4 = string(arr3);

    string str5 = "hello";
    char charr[10];
    strcpy(charr, str5.c_str());





    return 0;
}