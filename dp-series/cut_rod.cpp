#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int cutSegmentRec(int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }
    if(n > 0){
        return INT_MIN;
    }

    int cutx = cutSegmentRec(n - x, x, y, z);
    if(cutx != INT_MIN) cutx += 1;


    int cuty = cutSegmentRec(n - y, x, y, z);
    if(cuty != INT_MIN) cuty += 1;


    int cutz = cutSegmentRec(n - z, x, y, z);
    if(cutz != INT_MIN) cutz += 1;

    return max({cutx, cuty, cutz});
}


int cutSegmentMem(vector<int> &dp, int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }
    if(n > 0){
        return INT_MIN;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int cutx = cutSegmentMem(dp, n - x, x, y, z);
    if(cutx != INT_MIN) cutx += 1;


    int cuty = cutSegmentMem(dp, n - y, x, y, z);
    if(cuty != INT_MIN) cuty += 1;


    int cutz = cutSegmentMem(dp,n - z, x, y, z);
    if(cutz != INT_MIN) cutz += 1;

    return dp[n] = max({cutx, cuty, cutz});
}


int cutSegmentTab(int n, int x, int y, int z){

    vector<int> dp(n + 1, INT_MIN);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        if(i - x >= 0 && dp[i - x] != INT_MIN){
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if(i - y >= 0 && dp[i - y] != INT_MIN){
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if(i - z >= 0 && dp[i - z] != INT_MIN){
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    return dp[n] < 0 ? 0 : 0;
}

int main(){

        int n, x, y, z;
    cout << "Enter the value of n (rod length): ";
    cin >> n;

    cout << "Enter the value of x, y and z (segment lengths): ";
    cin >> x >> y >> z;

        cout << "--- Using Recursive Approach ---" << endl;

    int ans_rec = cutSegmentRec(n, x, y, z);

    if(ans_rec == INT_MIN){
        cout << "Max cuts : 0 (Impossible to cut) " << endl;
    } else {
        cout << "Max cuts : " << ans_rec << endl; 
    }

       cout << "--- Using Memoization Approach ---" << endl;
       vector<int> dp_memo(n+1, -1);
           int ans_mem = cutSegmentMem(dp_memo, n, x, y, z);

    if(ans_mem == INT_MIN){
        cout << "Max cuts : 0 (Impossible to cut) " << endl;
    } else {
        cout << "Max cuts : " << ans_mem << endl; 
    }

         cout << "--- Using Tabulation Approach ---" << endl;

    int ans_tab = cutSegmentTab(n, x, y, z);

    cout << "Max cuts : " << ans_tab << endl;

    return 0;
}