#include<iostream>
#include<vector>
using namespace std;

int minCosRes(vector<int> &stairs, int i){
    if(i < 0){
        return 0;
    }

    if(i <= 1){
        return stairs[i];
    }

    int cost_from_prev1 = minCosRes(stairs, i-1);
    int cost_from_prev2 = minCosRes(stairs, i-2);

    return stairs[i] + min(cost_from_prev1, cost_from_prev2);
}

int minCosMemo(vector<int> &stairs, int i, vector<int> &dp){
    if(i < 0){
        return 0;
    }

    if(i <= 1){
        return stairs[i];
    }

    if(dp[i] != 0) return dp[i];

    dp[i] = stairs[i] + min(minCosMemo(stairs, i-1, dp), minCosMemo(stairs, i-2, dp));

    return dp[i];
}

int minCostTab(vector<int> &stairs){
    int n = stairs.size();

    if(n == 0) return 0;

    if(n == 1) return stairs[0];

    vector<int> dp(n);

    dp[0] = stairs[0];
    dp[1] = stairs[1];

    for(int i = 2; i < n; i++){
        int prevCost = min(dp[i-1], dp[i-2]);
        dp[i] = stairs[i] + prevCost;
    }

    return min(dp[n-1], dp[n-2]);
}

int minCostSpaceopt(vector<int> &stairs){
    int n = stairs.size();

    if(n == 0) return 0;
    if(n == 1) return stairs[0];

    int prev0 = stairs[0];
    int prev1 = stairs[1];

    for(int i = 2; i < n; i++){
        int curr = stairs[i] = min(prev0, prev1);

        prev0 = prev1;
        prev1 = curr;
    }

    return min(prev0, prev1);
}

int main(){

    int n;
    cout << "Enter the count of stairs : ";
    cin >> n;

    vector<int> stairs(n);
    cout << "Enter the cost of stairs (space separated) : ";

    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }

    cout << "Costs: ";

    for(int cost: stairs){
        cout << cost << " ";
    }

    cout << endl;

    vector<int> dp_memo(n, 0);

    if(n == 0) ans = 0;
    else if(n == 1) ans = stairs[0];
    else ans = min(minCosMemo(stairs, n-1, dp_memo), minCosMemo(stairs, n-2, dp_memo));

    cout << "Minimum cost to reach the top: " << ans << endl;

    return 0;
}