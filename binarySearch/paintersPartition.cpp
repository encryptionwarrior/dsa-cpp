#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

bool isPossible(const vector<int>&board, int k, long long maxTime){
    int painterCount = 1;
    long long timeSpent = 0;

    for(int length : board){
        if(length > maxTime){
            return false;
        }

        timeSpent += length;
        if(timeSpent > maxTime){
            painterCount++;
            timeSpent = length;
        }
    }

    return painterCount <= k;
}

long long paintersPartition(const vector<int>& board, int k){
    long long s = *max_element(board.begin(), board.end());
    long long e = accumulate(board.begin(), board.end(), 0LL);
    long long ans = e;

    while(s <= e){
        long long mid = s + (e - s)/2;
        if(isPossible(board, k, mid)){
            ans = mid;
            e = mid -1;
        } else {
            s = mid + 1;
        }
    }
    return ans;

}

int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    long long minTime = paintersPartition(boards, k);
    cout << "Minimum time required to paint all boards: " << minTime << endl;
    return 0;
}