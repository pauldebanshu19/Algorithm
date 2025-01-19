#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(const vector<vector<int>> &board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
void solveNQueens(vector<vector<int>> &board, int row, int &solutionCount) {
    int n = board.size();
    if (row == n) {
        cout << "Solution " << ++solutionCount << ":" << endl;
        printSolution(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; 
            solveNQueens(board, row + 1, solutionCount); 
            board[row][col] = 0; 
        }
    }
}
int main() 
{
    int n;
    cout << "Enter the size of the chessboard (minimum 4): ";
    cin >> n;
    if (n < 4) {
        cout << "No solutions exist for a chessboard smaller than 4x4." << endl;
        return 0;
    }
    vector<vector<int>> board(n, vector<int>(n, 0));
    int solutionCount = 0;
    solveNQueens(board, 0, solutionCount);
    if (solutionCount == 0) {
        cout << "No solutions found." << endl;
    } else {
        cout << "Total solutions found: " << solutionCount << endl;
    }
    return 0;
}
