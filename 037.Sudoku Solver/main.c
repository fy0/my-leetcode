
// 很捉鸡
// 换语言了

#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

typedef struct {
	int len;
	int *data;
} Tuple;

int tuple_remove(Tuple *t, int key) {
	for (int i = 0; i < t->len; ++i) {
		if (t->data[i] == key) {
			t->data[i] = t->data[--t->len];
			return 1;
		}
	}
	return 0;
}

int tuple_remove_index(Tuple *t, int index) {
	if (!t->len) return 0;
	t->data[index] = t->data[--t->len];
	return 1;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	int *buf = (int*)malloc(sizeof(int) * (max(boardColSize, boardRowSize) + 1));
	Tuple possibleTable[100][100];
	memset(possibleTable, 0, sizeof(Tuple) * (100 * 100));

	// 横检查
	for (int i = 0; i < boardRowSize; ++i) {
		memset(buf, 0, sizeof(int) * (max(boardColSize, boardRowSize) + 1));
		int tlen = 0;
		for (int j = 0; j < boardColSize; ++j) {
			int val = board[i][j];
			if (val == '.') {
				tlen++;
				continue;
			}
			int key = val % boardColSize;
			buf[key] = 1;
		}

		int *possible = (int*)malloc(sizeof(int) * tlen);
		int n = 0;
		for (int j = 0; j < boardColSize; ++j) {
			if (!buf[j]) possible[n++] = buf[j];
		}

		for (int j = 0; j < tlen; ++j) {
			int key = possible[j];
			possibleTable[i][key].len = tlen;
			possibleTable[i][key].data = (int*)malloc(sizeof(int) * tlen);
			memcpy(possibleTable[i][key].data, possible, sizeof(int) * tlen);
		}
	}

	// 纵检查
	for (int i = 0; i < boardColSize; ++i) {
		memset(buf, 0, sizeof(int) * (max(boardColSize, boardRowSize) + 1));
		int tlen = 0;
		for (int j = 0; j < boardRowSize; ++j) {
			int val = board[j][i];
			if (val == '.') {
				tlen++;
				continue;
			}
			int key = val % boardRowSize;
			buf[key] = 1;
		}

		int *possible = (int*)malloc(sizeof(int) * tlen);
		int n = 0;
		for (int j = 0; j < boardRowSize; ++j) {
			if (!buf[j]) possible[n++] = buf[j];
		}

		for (int j = 0; j < tlen; ++j) {
			int key = possible[j];
			if (!possibleTable[key][i].len) {
				possibleTable[key][i].len = tlen;
				possibleTable[key][i].data = (int*)malloc(sizeof(int) * tlen);
				memcpy(possibleTable[key][i].data, possible, sizeof(int) * tlen);
			} else {
				int remove_lst[10];
				int rn = 0;
				// 遍历当前的信息表，如果不可能存在，将其移除
				for (int k = 0; k < possibleTable[key][i].len; ++k) {
					if (buf[possibleTable[key][i].data[k]] == 0) {
						remove_lst[rn++] = k;
					}
				}
				for (int k = 0; k < rn; ++k) {
					tuple_remove_index(&possibleTable[key][i], remove_lst[k]);
				}
			}
		}
	}

	// 方块检查
	for (int i = 0; i < boardRowSize / 3; ++i) {
		for (int j = 0; j < boardColSize / 3; ++j) {
			memset(buf, 0, sizeof(int) * (10));
			int tlen = 0;

			for (int x = 0; x < 3; ++x) {
				for (int y = 0; y < 3; ++y) {
					int val = board[i * 3 + x][j * 3 + y];
					if (val == '.') {
						tlen++;
						continue;
					}

					int key = val % 10;
					buf[key] = 1;
				}
			}

			int *possible = (int*)malloc(sizeof(int) * tlen);
			int n = 0;
			for (int j = 0; j < 10; ++j) {
				if (buf[j]) possible[n++] = buf[j];
			}

			for (int j = 0; j < tlen; ++j) {
				int key = possible[j];
				int x = key / 3;
				int y = key % 3;

				if (!possibleTable[x][y].len) {
					possibleTable[x][y].len = tlen;
					possibleTable[x][y].data = (int*)malloc(sizeof(int) * tlen);
					memcpy(possibleTable[key][i].data, possible, sizeof(int) * tlen);
				} else {
					int remove_lst[10];
					int rn = 0;
					// 遍历当前的信息表，如果不可能存在，将其移除
					for (int k = 0; k < possibleTable[x][y].len; ++k) {
						if (buf[possibleTable[x][y].data[k]] == 0) {
							remove_lst[rn++] = k;
						}
					}
					for (int k = 0; k < rn; ++k) {
						tuple_remove_index(&possibleTable[x][y], remove_lst[k]);
					}
				}
			}
		}
	}

	return;
}
