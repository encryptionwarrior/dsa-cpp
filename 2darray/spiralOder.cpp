#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;
    vector<int> ans;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total)
    {
        // Traverse top row (left to right)
        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // Traverse right column (top to bottom)
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // Traverse bottom row (right to left)
        for (int index = endingCol; count < total && index >= startingCol; index--)
        {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // Traverse left column (bottom to top)
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<int> spiral = spiralTraversal(matrix);

    cout << "Spiral items ++ ";
    for (int i = 0; i < spiral.size(); i++)
    {
        cout << spiral[i] << ' ';
    }
    return 0;
}
