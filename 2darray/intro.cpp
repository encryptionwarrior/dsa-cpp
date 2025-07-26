#include<iostream>
using namespace std;

int main(){
    // int arr[cols][rows];
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};


    int cols = 3;
    int rows = 2;

    // input
    cout << "enter values ";
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            cin >> arr[i][j];
        }
    }

    // output
    cout << "Print arr " << endl;
    for(int i = 0; i < cols; i++ ){
        for(int j = 0; j < rows; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }

    int** arr2 = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr2[i] = new int[cols];
    }

    // free memory 
    for(int i = 0; i < rows; i++){
        delete[] arr2[i];
    }
    delete[] arr;

// matrix addition
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j]
        }
    }

    // multiplication
    result[i][j] = sum(matrix1[i][k] * matrix2[k][j])
}