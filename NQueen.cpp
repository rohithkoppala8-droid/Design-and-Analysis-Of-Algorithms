#include <iostream>
#include <vector>
using namespace std;
int N;
int count = 0;
bool isSafe(vector<vector<int>>& board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
void solveNQueens(vector<vector<int>>& board, int row)
{
    if (row == N)
    {
        count++;
        cout << "\nSolution " << count << ":\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }
        return;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            // Backtracking
            board[row][col] = 0;
        }
    }
}
int main()
{
    cout << "Enter N: ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueens(board, 0);
    if (count == 0)
        cout << "No solution exists";
    else
        cout << "\nTotal solutions: " << count;
    return 0;
}
