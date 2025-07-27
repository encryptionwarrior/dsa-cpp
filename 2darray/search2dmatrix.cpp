#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>&matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();
    int rowIndex = 0;
    int colIndex = col - 1;

    while(rowIndex < row && colIndex >= 0){
        int element = matrix[rowIndex][colIndex];
        cout << "Check row & col " << element << ", " << target << ", " << colIndex << endl; 
        if(element == target){
            return true;
        } 
        if(element < target){
            rowIndex++;
        } else {
            colIndex--;
        }
    }

    return false;

}

int main(){
    vector<vector<int>> matrix = {{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}};
    int target = 9;

    bool findEl = searchMatrix(matrix, target);

    if(findEl){
        cout << "Element is found" << endl;
    } else {
        cout << "Element is not found" << endl;

    }



    return 0;
}