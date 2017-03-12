
#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int *buf = (int*)malloc(sizeof(int) * (max(boardColSize, boardRowSize) + 1));
    
    // 行列数目检查
    if (boardColSize > 9) return 0;
    if (boardRowSize > 9) return 0;
    if (boardColSize % 3 != 0) return false;
    if (boardRowSize % 3 != 0) return false;

    // 横检查
    for (int i = 0; i < boardRowSize; ++i) {
        memset(buf, 0, sizeof(int) * (max(boardColSize, boardRowSize) + 1));
        for (int j = 0; j < boardColSize; ++j) {
            int val = board[i][j];
            if (val == '.') continue;
            int key = board[i][j] % boardColSize;
            if (buf[key]) return false;
            buf[key] = 1;
        }
    }

    // 纵检查
    for (int i = 0; i < boardColSize; ++i) {
        memset(buf, 0, sizeof(int) * (max(boardColSize, boardRowSize) + 1));
        for (int j = 0; j < boardRowSize; ++j) {
            int val = board[j][i];
            if (val == '.') continue;
            int key = val % boardRowSize;
            if (buf[key]) return false;
            buf[key] = 1;
        }
    }

    // 方块检查
    for (int i = 0; i < boardRowSize / 3; ++i) {
        for (int j = 0; j < boardColSize / 3; ++j) {
            memset(buf, 0, sizeof(int) * (10));

            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    int val = board[i * 3 + x][j * 3 + y];
                    if (val == '.') continue;
            
                    int key = val % 10;
                    if (buf[key]) return false;
                    buf[key] = 1;
                }
            }
        }
    }
    
    return true;
}
