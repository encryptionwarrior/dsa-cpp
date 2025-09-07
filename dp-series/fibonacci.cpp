#include<iostream>
#include<vector>
using namespace std;

int fibRec(int n){
    if(n <= 1){
        return n;
    }

    return fibRec(n-1) + fibRec(n-2);
}

int fibDP_Memo(int n, vector<int> &dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fibDP_Memo(n-1, dp) + fibDP_Memo(n-2, dp);

    return dp[n];
}


int fibDP_Tab(int n){
    if(n <= 1) return n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int finDP_SPaceOpt(int n){
    if(n <= 1){
        return n;
    }

    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){

    int n;
    cout << "Enter n (to calculate Nth Fibonacci number : )";
    cin >> n;

    vector<int> dp(n + 1, -1);
    int ans = fibDP_Memo(n, dp);

    cout << "The " << n << "the Fibonaaci number is: " << ans << endl;



    return 0;
}