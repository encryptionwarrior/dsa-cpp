#include<iostream>
#include<vector>
#include<set>
using namespace std;

int totalWaysRec(int n){
    if(n<= 0) return 0;

    if(n <= 2) return n;

    return totalWaysRec(n-1) + totalWaysRec(n-2);
}

int totalWaysRec2(int n, int i){
    if(i == n) return 1;

    if(i > n) return 0;

    return totalWaysRec2(n, 1+1) + totalWaysRec2(n, i+2);
}

int totalWaysDP(int n, vector<int> &dp){
    if(n <= 0) return 0;
    if(n <= 2) return n;
    if(dp[n] != 0) return dp[n];

    dp[n] = totalWaysDP(n-1, dp) + totalWaysDP(n-2, dp);
    return dp[n];
}

int totalWaysDP2(int n){
        if(n <= 0) return 0;
    if(n <= 2) return n;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}
int totalWaysDP3(int n){
        if(n == 0) return 1;
    if(n == 1) return 1;

    int prev1 = 1;
    int prev2 = 1;

    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}



int main(){

    vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7,8, 9, 10, 15, 20, 25, 30, 35, 37};
    cout << "----------------------" << endl;

    for(int i = 0; i < input.size(); i++){
        int n_val = input[i];
        vector<int> dp_for_memo(n_val + 1, 0);

        cout << setw(2) << n_val << " | ";
        cout << setw(4) << totalWaysRec(n_val) << " | ";
        cout << setw(4) << totalWaysRec2(n_val, 0) << " | ";
        cout << setw(4) << totalWaysDP(n_val, dp_for_memo) << " | ";
        cout << setw(3) << totalWaysDP2(n_val) << " | ";
        cout << setw(8) << totalWaysDP2(n_val) << " | ";
    }

    return 0;
}