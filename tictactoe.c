#include <stdio.h>

// Function to print the current state of the Tic Tac Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to check if the current player has won
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

// Function to check if the board is full (draw)
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Function to get the player's move
void playerMove(char board[3][3], char player) {
    int row, col;
    printf("Player %c, enter your move (row column): ", player);
    scanf_s("%d %d", &row, &col);
    while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        printf("Invalid move! Please enter your move again (row column): ");
        scanf_s("%d %d", &row, &col);
    }
    board[row][col] = player;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int gameOver = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printBoard(board);

    while (!gameOver) {
        playerMove(board, currentPlayer);
        printBoard(board);
        if (checkWin(board, currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        }
        else if (checkDraw(board)) {
            printf("It's a draw!\n");
            gameOver = 1;
        }
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
