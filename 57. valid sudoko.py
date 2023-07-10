import sys
sys.setrecursionlimit(int(1e7))

def getBoxNo(i, j):
    return i // 3 * 3 + j // 3

def isItSudoku(mat):
    def isValid(board, row: int, col: int, c: str) -> bool:
        for i in range(9):
            if board[i][col] == c:
                return False
            if board[row][i] == c:
                return False
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
                return False
        return True
    def isSudoko(mat):

        for i in range(9):
            for j in range(9):
                if mat[i][j] != 0:
                    continue 
                for x in range(1,10):
                    if isValid(mat, i, j, x):
                        mat[i][j] = x
                        if isSudoko(mat):
                            mat[i][j] = 0
                            return True
                        mat[i][j] = 0
                return False
        return True
    tmp = isSudoko(mat)
    return tmp
