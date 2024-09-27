import time
import pdb

def print_board(board):
    for i in range(9):
        for j in range(9):
            print(board[i][j], end=" ")
        print()


def is_valid(board, row, col, num):
    # Check exist at 9 rows or 9 columns
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False

    # Check exist in 3x3 grid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False
    return True


def find_empty_location(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                return i, j
    return None


def solve_sudoku(board):
    empty_location = find_empty_location(board)

    if not empty_location:
        return True

    row, col = empty_location

    for num in range(1, 10):
        if is_valid(board, row, col, num):
            board[row][col] = num

            if solve_sudoku(board):
                return True
            board[row][col] = 0
            
    return False

def read_puzzle(address):
    puzzle = []
    f = open(address, 'r')
    for row in f:
        temp = row.split()
        puzzle.append([int(c) for c in temp])
    return puzzle

if __name__ == "__main__":
    sudoku_board = read_puzzle('sudoku1.in')

    if solve_sudoku(sudoku_board):
        print_board(sudoku_board)

    
    
 
