#include<iostream>
#include<vector>
using namespace std;

int rob_linear_rec(const vector<int> &arr, int index){
    if(index >= arr.size()){
        return 0;
    }

    int include_current = arr[index] + rob_linear_rec(arr, index + 1);
    int exclude_current =rob_linear_rec(arr, index + 1);

    return max(include_current, exclude_current);
}

int rob_linear_memo(const vector<int> &arr, int index, vector<int> &dp){
    if(index >= arr.size()){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

      int include_current = arr[index] + rob_linear_memo(arr, index + 2, dp);
    int exclude_current =rob_linear_memo(arr, index + 1, dp);

    return dp[index] = max(include_current, exclude_current);
}

int rob_linear_tab(const vector<int> &arr){
    int n = arr.size();

    if(n == 0) return 0;
    if(n == 1) return arr[0];

    vector<int> dp(n);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i = 2; i < n; i++){
        int include_curr = arr[i] + dp[i - 2];
        
        int exclude_curr = dp[i-1];

        dp[i] = max(include_curr, exclude_curr);

    }

    return dp[n - 1];

}


int rob_linear_opt(const vector<int> &arr){
    int n = arr.size();

    if(n == 0) return 0;
    if(n == 1) return arr[0];

    int prev2 = 0;
    int prev1 = arr[0];

    for(int i = 1; i < n; i++){
        int include_curr = arr[i] + prev2;
        
        int exclude_curr = prev1;

        int curr = max(include_curr, exclude_curr);

        prev2 = prev1;
        prev1 = curr;

    }

    return prev1;

}

int main(){

    vector<int> houses;
    cout << "Enter the money in each house (enter -1 to stop ) : ";
    int val;
    while(cin >> val && val != -1){
        houses.push_back(val);
    }

    int n = houses.size();

    if(n == 0){
        cout << "Maximum money that can be robbbed : 0 " << houses[0] << endl;

        return 0;
    }

    vector<int> house_exclude_last(houses.begin(), houses.end() - 1);

    int money_case1 = rob_linear_opt(house_exclude_last);


    vector<int> house_exclude_first(houses.begin() + 1, houses.end());

    int money_case2 = rob_linear_opt(house_exclude_first);

    int ans = max(money_case1, money_case2);

    cout << "Maximum money that can be robbed : " << ans << endl;

    return 0;
}