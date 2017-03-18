
// 172 / 172 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// 36.36% 

int comp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

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

		bool ret = choose(s, candidates, i+1, target - val, chooseNumber);
		sn--; // 还原状态

		for (int j = i + 1; j < chooseNumber; ++j) {
			if (candidates[j] != val) {
				i = j - 1; // 跳过相同的数字
				goto _next;
			}
		}
		break; // 证明后面所有数字都是一样的，没必要再找了
		_next:;
	}

	return false;
}


/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	qsort(candidates, candidatesSize, sizeof(int), &comp);

	int j = candidatesSize - 1;
	while (candidates[j] > target) j--;
	
	struct State s;

    s.n = 0;
	s.columnSizesData = (int*)malloc(300 * sizeof(int));
	s.ret = (int**)malloc(300 * sizeof(int*));

	int chooseNumber = j + 1;
	choose(&s, candidates, 0, target, chooseNumber);
	
    *columnSizes = s.columnSizesData;
    *returnSize = s.n;
    return s.ret;
}
