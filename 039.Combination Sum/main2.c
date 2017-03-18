
int comp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

// 全局变量不！能！用！
// 必然会报 free invalid pointer 错误！！！
// 并不知道为什么！！！valgrind一切正常！！
struct State {
    int n;
    int **ret;
    int *columnSizesData;
};

int stack[100];
int sn = 0;


bool choose(struct State *s, int *candidates, int limit, int target, int chooseNumber) {
	if (target < candidates[limit]) return false;

	for (int i = limit; i < chooseNumber; ++i) {
		int val = candidates[i];
		if (val > target) break;
		stack[sn++] = candidates[i];

		// 到达边界
		if (val == target) {
			// 保存
			int *buf = (int*)malloc(sizeof(int) * sn);
			memcpy(buf, stack, sizeof(int) * sn);
			s->ret[s->n] = buf;
			s->columnSizesData[s->n++] = sn;
			sn--;
			return true;
		}

		bool ret = choose(s, candidates, i, target - val, chooseNumber);
		sn--; // 还原状态
	}

	return false;
}


/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	qsort(candidates, candidatesSize, sizeof(int), &comp);

	int j = candidatesSize - 1;
	while (candidates[j] > target) j--;
	
	struct State s;

    s.n = 0;
	s.columnSizesData = (int*)malloc(300 * sizeof(int));
	s.ret = (int**)malloc(300 * sizeof(int*));

	// 如果当前数正好与 target 相同，那么直接返回
	int *buf;
	if (candidates[j] == target) {
		buf = (int*)malloc(sizeof(int));
		buf[0] = candidates[j];
		s.ret[s.n] = buf;
		s.columnSizesData[s.n++] = 1;
		j--;
	}

	int chooseNumber = j + 1;
	choose(&s, candidates, 0, target, chooseNumber);
	
    *columnSizes = s.columnSizesData;
    *returnSize = s.n;
    return s.ret;
}
