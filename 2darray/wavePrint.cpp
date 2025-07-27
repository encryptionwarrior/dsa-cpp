#include<iostream>
#include<vector>
using namespace std;

vector<int> waveTraverse(vector<vector<int>>&arr, int nRows, int mCols){
    vector<int> ans;
    for(int col = 0; col < mCols; col++){
        if(col & 1){
            for(int row = nRows - 1; row >= 0; row--){
                ans.push_back(arr[row][col]);
            }
        } else {
            for(int row = 0; row < nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
     {4, 5, 6}, 
     {7, 8, 9}
    };

    int nRows = arr[0].size();
    int mCols = arr.size();

    vector<int> wavedArr = waveTraverse(arr, nRows, mCols);

    cout << "Waved print => ";
    for(int i = 0; i < wavedArr.size(); i++){
        cout << wavedArr[i] << ", ";
    }
    return 0;
}