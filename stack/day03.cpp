#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> smallerElement(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> answer(n);

    for(int i = n - 1; i >= 0; i--){
        while(st.top() >= arr[i]){
            st.pop();
        }
        answer[i] = st.top();
        st.push(arr[i]);
    }

    return answer;
}

void checkSmallerElement(){
    vector<int> arr = {2, 3, 1};
    int n = arr.size();
    vector<int> ans = smallerElement(arr, n);

    cout << "Original array : ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "smaller array : ";

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
}

vector<int> nextSmallerElement(vector<int> arr){
    vector<int> solution(arr.size());
    stack<int> st;
    st.push(-1);


    for(int i = arr.size() - 1; i >= 0; i--){
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr){
            st.top();
        }

        solution[i] = st.top();
        st.push(i);
    }

    return solution;
}


vector<int> previousSmallerElement(vector<int> arr){
    vector<int> solution(arr.size());
    stack<int> st;
    st.push(-1);


    for(int i = 0; i < arr.size() ; i++){
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr){
            st.top();
        }

        solution[i] = st.top();
        st.push(i);
    }

    return solution;
}

int largestReactangularArea(vector<int> height){
    int n = height.size();
    int maxArea = 0;

    vector<int> next = nextSmallerElement(height);
    vector<int> prev = previousSmallerElement(height);

    for(int i = 0; i < n; i++){
        if(next[i] == -1){
            next[i] = n;
        }

        int length = height[i];
        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;
        maxArea = max(newArea, maxArea);
    }

    return maxArea;

}

int main(){

    vector<int> height = {2, 1, 5, 6, 2, 3};
 cout << "Required area : " << largestReactangularArea(height) << endl;



    checkSmallerElement();
    return 0;
}