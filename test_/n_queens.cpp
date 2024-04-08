#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solveNQueens(vector<string> &board, int col, int n, vector<vector<string>> &res)
{
    if (col >= n)
    {
        res.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (canPlace(board, i, col, n))
        {
            board[i][col] = 'Q';
            solveNQueens(board, col + 1, n, res);
            board[i][col] = '.';
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> res;
    solveNQueens(board, 0, n, res);
    sort(res.rbegin(), res.rend());
    if (res.size() == 0)
        cout << "None\n";
    else
        for (auto &board : res)
        {
            for (string &row : board)
            {
                for (char &c : row)
                    cout << c << " ";
                cout << "\n";
            }
            cout << "\n";
        }
    return 0;
}