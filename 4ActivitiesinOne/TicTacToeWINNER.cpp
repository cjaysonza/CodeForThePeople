#include <iostream>

char whoWon(char board[3][3]);
void showBoard(char board[3][3]);

int main() {
    char board[3][3] = {
        {'O', 'O', 'O'},  //
        {'O', 'X', '-'},  //
        {'-', 'X', 'O'},  //
    };

    showBoard(board);
    char winner = whoWon(board);

    std::cout << std::endl;
    std::cout << std::endl;
    if (winner == '-') {
        std::cout << "No one has won the game yet";
    } else {
        std::cout << winner << " is the Winner ";
    }
    return 0;
}

void showBoard(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            std::cout << board[row][column] << " ";
        }
        std::cout << std::endl;
    }
}
char whoWon(char board[3][3]) {
    // For ROW checking of winner
    for (int row = 0; row < 3; row++) {
        int xCount = 0, oCount = 0;
        for (int column = 0; column < 3; column++) {
            if (board[row][column] == 'X') {
                xCount++;
            } else if (board[row][column] == 'O') {
                oCount++;
            }
        }
        if (xCount == 3) {
            return 'X';
        }
        if (oCount == 3) {
            return 'O';
        }
    }

    // For COLUMN checking of winner
    for (int column = 0; column < 3; column++) {
        int xCount = 0, oCount = 0;
        for (int row = 0; row < 3; row++) {
            if (board[row][column] == 'X') {
                xCount++;
            } else if (board[row][column] == 'O') {
                oCount++;
            }
        }
        if (xCount == 3) {
            return 'X';
        }
        if (oCount == 3) {
            return 'O';
        }
    }

    // For Diagonal Winner NW to SE
    {
        int xCount = 0, oCount = 0;
        for (int diagonal1 = 0; diagonal1 < 3; diagonal1++) {
            if (board[diagonal1][diagonal1] == 'X') {
                xCount++;
            } else if (board[diagonal1][diagonal1] == 'O') {
                oCount++;
            }
        }
        if (xCount == 3) {
            return 'X';
        }
        if (oCount == 3) {
            return 'O';
        }
    }

    // For Diagonal Winner NE to SW
    {
        int xCount = 0, oCount = 0;
        for (int row = 2, column = 0; row >= 0 && column < 3; row--, column++) {
            if (board[row][column] == 'X') {
                xCount++;
            } else if (board[row][column] == 'O') {
                oCount++;
            }
        }
        if (xCount == 3) {
            return 'X';
        }
        if (oCount == 3) {
            return 'O';
        }
    }

    return '-';
}
