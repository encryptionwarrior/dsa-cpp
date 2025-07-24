#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>&nums, int k){
    int n = nums.size();
    vector<int>temp(n);

    for(int i = 0; i < n; i++){
        temp[(i+k)%n] = nums[i];
    }

    for(int i = 0; i < temp.size(); i++){
        nums[i] = temp[i];
    }



    cout << "Here is k rotated array => " ;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}

int main(){
    vector<int>nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);

    return 0;

}