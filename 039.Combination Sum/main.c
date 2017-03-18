
// 这个复杂度我已经无法掌控了
// 我完全不知道树里的东西是什么

int comp(const void *a, const void *b) {
	return (int*)a - (int*)b;
}

typedef struct {
	int type; // list or node
	int sum;
} SearchObject;

typedef struct {
	int type;
	int sum;
	int len;
	SearchObject *val[10];
} SearchAndList;

typedef SearchObject SearchNode;
typedef SearchAndList SearchOrList;

SearchNode* search_node_new(int sum) {
	SearchNode *obj = (SearchNode*)malloc(sizeof(SearchNode));
	obj->type = 1;
	obj->sum = sum;
	return obj;
}

SearchAndList* _search_list_new(int sum, int type) {
	SearchAndList *obj = (SearchAndList*)malloc(sizeof(SearchAndList));
	obj->type = type;
	obj->sum = sum;
	obj->len = 0;
	return obj;
}

SearchAndList* search_list_and_new(int sum) {
	return _search_list_new(sum, 2);
}

SearchOrList* search_list_or_new(int sum) {
	return (SearchOrList*)_search_list_new(sum, 3);
}

typedef struct {
	int stack[1000][100];
	int sn[100];
	int len;

} StackState;

/*void get_stack2(StackState *s, SearchObject *obj) {
	if (obj->type == 1) {
		s->state[s->sn++] = 0;
	}
	if (obj->type == 2) {
		s->state[s->sn++] = 0;
		for (int i = 0; i < ((SearchAndList*)obj)->len; ++i) {
			get_stack2(s, ((SearchAndList*)obj)->val[i]);
		}
	}
	if (obj->type == 2) {
		s->state[s->sn++] = 0;
	}
}*/

void get_stack(StackState *s, SearchObject *obj) {
	int *stack = (int*)(s->stack)[s->len];

	if (obj->type == 1) {
		for (int j = 0; j < s->len + 1; ++j) {
			int *psn = (s->sn) + j;
			s->stack[j][(*psn)++] = obj->sum;
		}
	}

	if (obj->type == 2) {
		for (int i = 0; i < ((SearchAndList*)obj)->len; ++i) {
			get_stack(s, ((SearchAndList*)obj)->val[i]);
		}
	}

	if (obj->type == 3) {
		/*for (int i = 0; i < ((SearchAndList*)obj)->len; ++i) {
			get_stack(s, ((SearchAndList*)obj)->val[i]);
		}*/
		int *psn = (s->sn) + s->len;
		//int keep = *psn;

		/*for (int i = 0; i < ((SearchAndList*)obj)->len; ++i) {
			for (int j = 0; j < s->len + 1; ++j) {
				int index = (s->len + 1) * (i + 1) + j;
				s->sn[index] = s->sn[i + j];
				memcpy(s->stack[index], s->stack[i + j], sizeof(int) * 100);
			}
		}*/

		for (int i = 0; i < ((SearchAndList*)obj)->len; ++i) {
			get_stack(s, ((SearchAndList*)obj)->val[i]);
			int *psn = (s->sn) + s->len;
			//s->len++;
			//s->sn[s->len] = keep;
			//memcpy((s->stack)[s->len], stack, keep * sizeof(int));
		}
	}
}

// 初始化表格
SearchObject** searchTable = (SearchObject**)malloc(sizeof(SearchObject*) * 100);
int stn = 0;

SearchObject* findBySum(int sum) {
	for (int i = 0; i < stn; ++i) {
		if (searchTable[i]->sum == sum) return searchTable[i];
	}
	return NULL;
}

SearchObject* choose(int *candidates, int limit, int target, int chooseNumber) {
	// 做一个选择
	int n = 0;

	// 到达边界了吗？
	SearchObject *node = findBySum(target);
	if (node) return node;

	SearchOrList *orlst = search_list_or_new(target);

	for (int i = limit; i < chooseNumber; ++i) {
		int val = candidates[i];
		if (val > target) break;
		SearchNode *node = findBySum(val);
		SearchNode *node2 = choose(candidates, limit, target - node->sum, chooseNumber);
		if (node2) {
			SearchAndList *andlst = search_list_and_new(target);
			if (node->type == 2) {
				for (int i = 0; i < ((SearchAndList*)node)->len; ++i) {
					andlst->val[andlst->len++] = ((SearchAndList*)node)->val[i];
				}
			} else andlst->val[andlst->len++] = node;

			if (node2->type == 2) {
				for (int i = 0; i < ((SearchAndList*)node2)->len; ++i) {
					andlst->val[andlst->len++] = ((SearchAndList*)node2)->val[i];
				}
			} else andlst->val[andlst->len++] = node2;
			orlst->val[orlst->len++] = (SearchObject*)andlst;
		}
	}

	if (orlst->len > 0) return (SearchObject*)orlst;
	return NULL;
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

	int n = 0;
	int size = 100;

	int **ret = (int**)malloc(100 * sizeof(int*));
	int *columnSizesData = (int*)malloc(100 * sizeof(int*));

	// 如果当前数正好与 target 相同，那么直接返回
	int *buf;
	if (candidates[j] == target) {
		buf = (int*)malloc(sizeof(int));
		buf[0] = candidates[j];
		ret[n] = buf;
		columnSizesData[n++] = 1;
		j--;
	}

	int chooseNumber = j + 1;

	for (int i = 0; i < chooseNumber; ++i) {
		searchTable[i] = search_node_new(candidates[i]);
	}
	stn = chooseNumber;

	SearchObject* obj = choose(candidates, 0, target, chooseNumber);

	StackState s;
	s.len = 0;
	s.sn[0] = 0;
	get_stack(&s, obj);

	*columnSizes = columnSizesData;
	*returnSize = n;
	return ret;
}

