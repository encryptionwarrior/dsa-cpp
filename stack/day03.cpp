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

int findCelebrity(vector<vector<int>> matrix){
    stack<int> st;
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        st.push(i);
    }

    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(matrix[a][b] == 1){
            st.push(b);
        } else {
            st.push(a);
        }
    }

    int candidate = st.top();

    for(int i = 0; i < n; i++){
        if(matrix[candidate][i] == 1){
            return -1;
        }
    }

    for(int i = 0; i < n; i++){
        if(matrix[i][candidate] == 0 && i != candidate){
            return -1;
        }
    }

    return candidate;
}

void celebrityProblem(){
    vector<vector<int>> matrix;
    int size;

    cout << "Enter the size (N) of the matrix : ";
    cin >> size;

    cout << "Enter the matrix elements (0s and 1s, n * N):" << endl;

    for(int i = 0; i < size; i++){
        vector<int> row(size);
        for(int j = 0; j < size; j++){
            cin >> row[j];
        }
        matrix.push_back(row);
    }

}

// max reactangle matrix
int maxArea(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int area = largestReactangularArea(matrix[0]);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != 0){
                matrix[i][j] += matrix[i-1][j];
            } else {
                matrix[i][j] = 0;
            }
        } 

        int currArea = largestReactangularArea(matrix[i]);
        area = max(area, currArea);
    }

    return area;
}

void getMaxMatrix(){
    vector<vector<int>> matrix;
    int size;

    cout << "Enter the size (N for N * N ): ";
    cin >> size;

    cout << "Enter the matrix elements (0s and 1s, N * N) : " << endl;

    for(int i = 0; i < size; i++){
        vector<int> temp_row(size);
        for(int j = 0; j < size; j++){
            cin >> temp_row[i];
        }
        matrix.push_back(temp_row);

    }

    cout << "Maximum area of reactangle of 1s: " << maxArea(matrix) << endl;
}


int main(){

//     vector<int> height = {2, 1, 5, 6, 2, 3};
//  cout << "Required area : " << largestReactangularArea(height) << endl;



    // checkSmallerElement();
    // celebrityProblem();
    getMaxMatrix();
    return 0;
}