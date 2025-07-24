#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isPossibel(vector<int>&stalls, int k, int mid, int n){
    int cowCount = 1;
    int lasPos = stalls[0];
    for(int i = 0; i < n; i++){
        if(stalls[i] - lasPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lasPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int>&stalls, int k){
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int n = stalls.size();
    int e = stalls[n-1];
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s <= e){
        if(isPossibel(stalls, k, mid, n)){
            ans = mid;
            s = mid + 1;
        } else {
            e = mid -1;
        }
        mid = s + (e - s)/2;
    }
    return ans;

}


int main(){
    vector<int>stalls = {1, 2, 4, 9, 8};
    int k = 3;
    int aggCow = aggressiveCows(stalls, k);
    cout << "Aggressive cows ++" << aggCow << endl;
    return 0;
}