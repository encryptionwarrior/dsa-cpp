#include<iostream>
#include<vector>
using namespace std;

int maxSumRec(vector<int> &nums, int index, int sum){
    if(index >= nums.size()){
        return sum;
    }

    int inc = maxSumRec(nums, index + 2, sum + nums[index]);

    int exec = maxSumRec(nums, index + 1, sum);

    return max(inc, exec);
}

int maxSumMem(vector<int> &nums, int index, vector<int> &dp){
    if(index >= nums.size()){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    int inc = nums[index] + maxSumMem(nums, index + 2, dp);

    int exec = maxSumMem(nums, index + 1, dp);

    dp[index] = max(inc, exec);

    return dp[index];
}

int maxSumTab(vector<int> &nums){
    int n = nums.size();

    if(n == 0) return 0;
    if(n == 1) return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];

    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++){
        int inc = nums[i] + dp[i-2];

        int exc = dp[i-1];

        dp[i] = max(inc, exc);
    }

    return dp[n - 1];
}


int maxSumSpc(vector<int> &nums){
    int n = nums.size();

    if(n == 0) return 0;
    if(n == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; i++){
        int inc = nums[i] + prev2;

        int exc = prev1;
        int curr = max(inc, exc);

        prev2 = prev1;
        prev1 = curr;

    }

    return prev1;
}

int main(){

    vector<int> nums;

    cout << "Enter the array elemnts (enter -1 to stop: )";

    int val;

    cin >> val;

    while(val != -1){
        nums.push_back(val);
        cin >> val;
    }

    if(nums.empty()){
        cout << "Maximum sum of non-adjacent elements : 0 " << endl;
        return 0;
    }

    vector<int> dp_memo(nums.size(), -1);

    int ans = maxSumSpc(nums);

    cout << "Maximum sum of non-adjacent elements : " << ans << endl;

    return 0;

}