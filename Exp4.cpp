#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createBoard(vector<vector<string>> &ans, int n, vector<int> &positions) {
        vector<string> board(n, string(n, '#'));
        for (int i = 0; i < positions.size(); i++) {
            board[i][positions[i]] = 'Q';
        }
        ans.push_back(board);
    }

    bool isValid(int row, int col, vector<int> &positions) {
        for (int i = 0; i < row; i++) {
            if (positions[i] == col || abs(row - i) == abs(col - positions[i])) {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>> &ans, int n, int row, vector<int> &positions) {
        if (row == n) {
            createBoard(ans, n, positions);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col, positions)) {
                positions.push_back(col);
                backtrack(ans, n, row + 1, positions);
                positions.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<int> positions;
        backtrack(solutions, n, 0, positions);
        return solutions;
    }
};

int main() {
    int input;
    cout << "Enter size of board: ";
    cin >> input;
    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(input);

    int i = 1;
    for (const auto &config : results) {
        cout << i << " Configuration:\n\n";
        for (const auto &row : config) {
            cout << row << endl;
        }
        cout << endl;
        i++;
    }
    return 0;
}

