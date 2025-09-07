#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minElementsRec(vector<int> &coins, int target){
    if(target == 0) return 0;

    if(target < 0) return INT_MAX;

    int mini = INT_MAX;

    for(int i = 0; i < coins.size(); i++){
        int ans = minElementsRec(coins, target - coins[i]);

        if(ans != INT_MAX){
            mini = min(mini, ans + 1);
        }
    }

    return mini;
}

int minElementDP(vector<int> &dp, vector<int> &coins, int target){
        if(target == 0) return 0;

    if(target < 0) return INT_MAX;

    if(dp[target] != -1) return dp[target];

    int mini = INT_MAX;

    for(int i = 0; i< coins.size(); i++){
        int ans = minElementDP(dp, coins, target - coins[i]);

        if(ans != INT_MAX){
            mini = min(mini, ans + 1);
        }
    }

    dp[target] = mini;
    return mini;
}

int miniElementstab(vector<int> &coins, int target){
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= target; i++){
        for(int c = 0; c < coins.size(); c++){
            if(i - coins[c] >= 0 && dp[i - coins[c]] != INT_MAX){
                dp[i] = min(dp[i], dp[i - coins[c]]+ 1);
            }
        }
    }

    return dp[target];
}


int main(){
    vector<int> coins;

    int tagret;

    cout << "Enter the coins array (enter -1 to stop) : ";
    int temp;
    while(temp != -1){
        coins.push_back(temp);
        cin >> temp;
    }

    cout << "Enter the target amount : ";
    cin >> tagret;

    int minCoin = miniElementstab(coins, tagret);

    if(minCoin != INT_MAX){
        cout << "Required minimum cost : " << minCoin << endl;
    } else {
        cout << "Required minimum cost : " << -1 << endl;

    }

    return 0;
}