#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentToken = 'X';
int row, column;
int isGameActive = 1;  // 1 means true, 0 means false

void drawBoard();
void placeToken();
int checkWin();

int main() {
    printf("--- TIC TAC TOE GAME --\n");
    printf("Player 1: X  |  Player 2: O \n\n");

    int status = 0;  // 0: Running, 1: Win, -1: Draw
    int moves = 0;

    while(status == 0 && moves < 9) {
        drawBoard();
        placeToken();
        status = checkWin();

        if(status == 0) {
            // Switch player for next turn
            if(currentToken == 'X') {
                currentToken = 'O';
            } 
            else {
                currentToken = 'X';
            }
        }
        moves++;
    }

    drawBoard();  // Show final board..

    if(status == 1) {
        printf("\nResult: Player %c Wins! Congratulations!! \n", currentToken);
    } else {
        printf("\nResult: It's Draw! Well played both!! \n");
    }

    return 0;
}

// To draw the Tic-Tac-Toe Board
void drawBoard() {
    printf("\n");
    printf("  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf(" ---|---|--- \n");
    printf("  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf(" ---|---|--- \n");
    printf("  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// This Function to take input and place X or O
void placeToken() {
    int choice;
    printf("Player %c, enter a number (1-9): ", currentToken);
    scanf("%d", &choice);

    // Logic to map 1-9 to array indexes
    if (choice == 1) { row=0; column=0; }
    else if (choice == 2) { row=0; column=1; }
    else if (choice == 3) { row=0; column=2; }
    else if (choice == 4) { row=1; column=0; }
    else if (choice == 5) { row=1; column=1; }
    else if (choice == 6) { row=1; column=2; }
    else if (choice == 7) { row=2; column=0; }
    else if (choice == 8) { row=2; column=1; }
    else if (choice == 9) { row=2; column=2; }
    else {
        printf("Invalid move! Try again.\n");
        placeToken(); // Call again
        return; 
    }

    // Check if the space is already taken..
    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = currentToken;
    } else {
        printf("Spot already taken! Choose another.\n");
        placeToken(); 
    }
}

// Function to check if someone has won...
int checkWin() {
    // Check Rows
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) return 1;
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) return 1;
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) return 1;

    // Check Columns
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0]) return 1;
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) return 1;
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) return 1;

    // Check Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0; // No win yet
}

