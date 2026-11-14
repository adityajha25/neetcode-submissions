class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row[i][5] = does the ith row have 5?
        bool rows[9][9] = {false};
        // cols[j][2] = does the ith col have 2?
        bool cols[9][9] = {false};
        // squares[i][1]: does the ith square have 1?
        //ith square:  + (j/3)
        bool squares[9][9] = {false};

        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board.size();j++) {
                if (board[i][j] - '.' != 0) {
                    int num=board[i][j] -'1';
                    int row=i;
                    int col=j;
                    int box = 3*(i/3) + (j/3);
                    if (rows[i][num] || cols[j][num] || squares[box][num]) {
                        return false;
                    }
                    rows[i][num]=true;
                    cols[j][num]=true;
                    squares[box][num]=true;

                }
            }
        }
        return true;

    }
};
