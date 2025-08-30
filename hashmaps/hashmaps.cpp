#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

void unOrderedMap(){
    map<string, int> M;

    pair<string, int> pair1 = make_pair("white", 2);
    M.insert(pair1);

    pair<string, int> pair2("black", 3);
    M.insert(pair2);

    M["red"] = 4;

    cout << "Before updation : white = " << M["white"] << endl;
    
    M["white"] = 10;
    cout << "After updation : white = " << M.at("white") << endl;
    cout << "Value of non-existent key 'orange' using [] = " << M["orange"] << endl;

    cout << "Size : " << M.size() << endl;

    cout << "Is 'yellow' present? (0=NO, 1=Yes) : " << M.count("yellow") << endl;
    cout << "Is 'white' present? (0=NO, 1=Yes) : " << M.count("white") << endl;

    M.erase("white");

    cout << "SIze after erasing white : " << M.size() << endl;

    cout << "Elements in map after removal (sorted by keys) : " << endl;

    for(auto i : M){
        cout << i.first << " & " << i.second << endl;
    }



}


int maximumFrequency(vector<int> arr, int n){
    unordered_map<int, int> M;

    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        M[arr[i]]++;

        maxi = max(maxi, M[arr[i]]);
    }

    for(int i = 0; i < n; i++){
        if(M[arr[i]] == maxi){
            return arr[i];
        }
    }

    return -1;
}

int main(){

    vector<int> arr;

    cout << "Enter the elements of array (enter -1 to stop) : ";
    int data;
    cin >> data;

    while(data != -1){
        arr.push_back(data);
        cin >> data;
    }

    int ans = maximumFrequency(arr, arr.size());

    cout << "elements with maximum frequency : " << ans << endl;

    // unOrderedMap();
    return 0;
}