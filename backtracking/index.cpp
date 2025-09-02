#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>maze, vector<vector<int>> visited, int n, int newX, int newY){
    return ((newX >= 0) && (newX < n) && (newY >= 0) && (maze[newX][newY] == 1) && (visited[newX][newY] == 0));
};

void paths(vector<string> &answer, vector<vector<int>>&maze, vector<vector<int>> &visited, string path, int x, int y, int n){
    if(x == n - 1 && y == n - 1){
        answer.push_back(path);
        return;
    }

    visited[x][y] = 1;

    int newX, newY;
    newX = x + 1;
    newY = y;

    if(isSafe(maze, visited, n, newX, newY)){
        path.push_back('D');
        paths(answer, maze, visited, path, newX, newY, n);
        path.pop_back();
    }

    newX = x;
    newY = y - 1;

    if(isSafe(maze, visited, n, newX, newY)){
        path.push_back('L');
        paths(answer, maze, visited, path, newX, newY, n);
        path.pop_back();
    }

    newX = x;
    newY = y + 1;

    if(isSafe(maze, visited, n, newX, newY)){
        path.push_back('R');
        paths(answer, maze, visited, path, newX, newY, n);
        path.pop_back();
    }

    newX = x - 1;
    newY = y;

    if(isSafe(maze, visited, n, newX, newY)){
        path.push_back('U');
        paths(answer, maze, visited, path, newX, newY, n);
        path.pop_back();
    }

    visited[x][y] = 0;

}


vector<string> searchMaze(vector<vector<int>> &arr, int n){
    vector<vector<int>>visited(n, vector<int>(n, 0));
    vector<string> answer;


    if(arr[0][0] != 0){
        paths(answer, arr, visited, "", 0, 0, n);
    }

    return answer;
}

void ratInMaze(){
    vector<vector<int>> maze;

    int n = 4;

    cout << "Enter the maze (0 for blocked, 1 for open path) : " << endl;
    for(int i = 0; i < n; i++){
        vector<int> temp_row(n);
        for(int j = 0; j < n; j++){
            cin >> temp_row[j];
        }
        maze.push_back(temp_row);
    }

    vector<string> all_paths = searchMaze(maze, n);
    

    cout << "All possible paths : ";
    if(all_paths.empty()){
        cout << "No path found." << endl;
    } else {
        for(string s: all_paths){
            cout<< s << " ";
        }

        cout << endl;
    }

}

int main(){
    ratInMaze();
    return 0;
}