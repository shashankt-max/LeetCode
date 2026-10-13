bool check(char board[3][3], char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;

        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }

    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;

    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;

    return false;
}

char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    char board[3][3] = {0};

    for (int i = 0; i < movesSize; i++) {
        int r = moves[i][0];
        int c = moves[i][1];

        char player = (i % 2 == 0) ? 'X' : 'O';
        board[r][c] = player;

        if (check(board, player)) {
            return (i % 2 == 0) ? "A" : "B";
        }
    }

    if (movesSize == 9)
        return "Draw";

    return "Pending";
}