class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<int>> rowSets(9);
        std::unordered_map<int, std::unordered_set<int>> colSets(9);
        std::unordered_map<int, std::unordered_set<int>> squareSets(9);

        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] - '.' != 0) {
                    int num=board[i][j];
                    int row=i;
                    int col=j;
                    int square = 3 * (i/3) + (j/3);
                    // (2,2) = (0,0) = 2 * 0 + 0
                    // (8,7) = (2, 2)
                    // (0,8) = (0,2)
                    if (rowSets[row].contains(num)) {
                        return false;
                    } else {
                        rowSets[row].insert(num);
                    }
                    if (colSets[col].contains(num)) {
                        return false;
                    } else {
                        colSets[col].insert(num);
                    }
                    if (squareSets[square].contains(num)) {
                        return false;
                    } else {
                        squareSets[square].insert(num);
                    }
                }
            }
        }
        return true;
    }
};
