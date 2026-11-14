class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows=[[False] * 9 for _ in range(0,9)]
        cols=[[False] * 9 for _ in range(0,9)]
        squares=[[False] * 9 for _ in range(0,9)]

        for i in range(len(board)):
            for j in range(len(board[i])):
                num = board[i][j]
                if num == ".":
                    continue
                num=int(num) - 1
                box = 3 * (i//3) + (j//3)
                if rows[i][num] or cols[j][num] or squares[box][num]:
                    return False
                else:
                    rows[i][num]=True
                    cols[j][num]=True
                    squares[box][num]=True
        
        return True