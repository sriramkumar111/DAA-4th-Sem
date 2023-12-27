#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int boardSize = 4;
int board[10];
int solutionCount = 0;

int canPlace(int row, int col)
{
    for (int prevRow = 1; prevRow < row; prevRow++)
    {
        if (board[prevRow] == col || abs(prevRow - row) == abs(board[prevRow] - col))
            return 0;
    }
    return 1;
}

void solveNQueens(int row, int boardSize)
{
    for (int col = 1; col <= boardSize; col++)
    {
        if (canPlace(row, col))
        {
            board[row] = col;
            if (row == boardSize)
            {
                solutionCount++;
                for (int i = 1; i <= boardSize; i++)
                {
                    printf("%d ", board[i]);
                }
                printf("\n");
            }
            else
                solveNQueens(row + 1, boardSize);
        }
    }
}

int main()
{
    solveNQueens(1, boardSize);
    printf("Number of solutions: %d\n", solutionCount);
    return 0;
}

