#include<iostream>
#include<vector>
#include<map>
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


void addSolution(vector<vector<int>> board, vector<vector<int>> & sol){
    vector<int> temp;

    for(vector<int> row_vec: board){
        for(int cell_val: row_vec){
            temp.push_back(cell_val);
        }
    }
    sol.push_back(temp);
}


bool isSafeQueen(int row, int col, vector<vector<int>> board, int n){
    for(int j = col; j >= 0; j--){
        if(board[row][j] == 1){
            return false;
        }
    }


    for(int i= row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }


    for(int i= row, j = col; i < n && j >= 0; i++, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

void solve(int col, vector<vector<int>> &solution, vector<vector<int>> &board, int n){
    if(col == n){
        addSolution(board, solution);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafeQueen(row, col, board, n)){
            board[row][col] = 1;

            solve(col + 1, solution, board, n);

            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> solution;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, solution, board, n);
    return solution;
}

void NQueens(){
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    vector<vector<int>> solution = nQueens(n);

    int i = 0;
    if(solution.empty()){
        cout << "\nNo possible configurations for n = " << n << endl;
    } else {
        for(vector<int> config: solution){
            cout << endl << "Possilbe configuration [" << ++i << "] : ";
            for(int val: config){
                cout << val << " ";
            }
        }

        cout << endl;
    }
}

map<int, bool> rowCheck;
map<int, bool> upperCheck;
map<int, bool> lowerCheck;

bool isSafeQueensHashMaps(int row, int col, int n){
    return !(rowCheck[row] == true || upperCheck[row + col] == true || lowerCheck[n + row - col] == true);
}

void solveHashMaps(int col, vector<vector<int>> & solution, vector<vector<int>> &board, int n){
    if(col == n){
        addSolution(board, solution);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafeQueensHashMaps(row, col, n)){
            board[row][col] = 1;

            rowCheck[row] = true;
            upperCheck[row+col] = true;
            lowerCheck[n + row - col] = true;

            solveHashMaps(col + 1, solution, board, n);

            board[row][col] = 0;

            rowCheck[row] = false;
            upperCheck[row + col] = false;
            lowerCheck[n + row - col] = false;
        }
    }
}

vector<vector<int>> nQueensHashmaps(int n){
    vector<vector<int>> solution;

    vector<vector<int>> board(n, vector<int>(n, 0));

    rowCheck.clear();
    upperCheck.clear();
    lowerCheck.clear();

    solveHashMaps(0, solution, board, n);
    return solution;
}

void NQUEENSHASHMAPS(){
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    vector<vector<int>> solution = nQueensHashmaps(n);
    int i = 0;

    if(solution.empty()){
        cout << "\nNo possible configurations for n = " << n << endl;
    } else {
        for(vector<int> config : solution){
            cout << endl << "Possible configuration [" << ++i << "] : ";
            for(int val: config){
                cout << val << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    // ratInMaze();
    // NQueens();
    NQUEENSHASHMAPS();
    return 0;
}