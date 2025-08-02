#include<iostream>
#include<vector>
using namespace std;

void solved(vector<string>& ans, string str, string output, int i) {
    if(i >= str.length()){
        if(output.length() > 0){
            ans.push_back(output);
        }
        return;
    }

    // Exclude current character
    solved(ans, str, output, i + 1);

    // Include current character
    solved(ans, str, output + str[i], i + 1);
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    solved(ans, str, output, 0);
    return ans;
}

void solved2(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    solved2(nums, output, index + 1, ans);

    int element = nums[index];
    output.push_back(element);

    solved2(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solved2(nums, output, index, ans);
    return ans;
}

int main(){
    string str = "abc";
    vector<string> result = subsequences(str);

    cout << "Subsequences are => " << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    cout << endl;


    vector<int> nums = {1, 2, 3};
    vector<vector<int>> substess = subsets(nums);

  cout << "subsets are => " << endl;
    for(int i = 0; i < substess.size(); i++){
        for(int j = 0; j < substess[i].size(); j++){
            cout << substess[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
