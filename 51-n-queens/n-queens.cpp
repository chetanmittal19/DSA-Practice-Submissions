class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> arr(n, string(n, '.'));

        queenTry(ans, arr, 0, n);
        return ans;
    }

    void queenTry(vector<vector<string>>& ans, vector<string>& arr, int row, int n) {
        if (row == arr.size()) {
            ans.push_back(arr);
            return;
        }
        for (int col = 0; col < arr.size(); col++) {
            if (safe(arr, col, n, row)) {
                arr[row][col] = 'Q';
                queenTry(ans, arr, row + 1, n);
                arr[row][col] = '.';
            }
        }
    }

    bool safe(const vector<string>& arr, int col, int n, int row) {
        for (int i = row-1; i>=0; i--){
            if (arr[i][col]=='Q'){
                return false;
            }
        }
        for (int i = row-1, j = col-1; i>=0 && j>=0; i--, j--){
            if (arr[i][j]=='Q'){
                return false;
            }
        }
        for (int i = row-1, j = col + 1; i>=0 && j<n; i--, j++){
            if (arr[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
};