
void nextPermutation(int* buf, int len) {
	// 1,2,3
	// 1,3,2
	int i = len - 1;
	while (i > 0 && buf[i] <= buf[i - 1]) {
		i--;
	}
	if (i == 0) {
	    int a = 0;
	    int b = len - 1;
    	while (a < b) {
    		int tmp = buf[a];
    		buf[a] = buf[b];
    		buf[b] = tmp;
    		a++;
    		b--;
    	}
    	return;
	}

	int minpos = i;
	int minnum = buf[i];
	for (int j = i; j < len; ++j) {
		if (buf[j] > buf[i-1] && buf[j] <= minnum) {
			minnum = buf[j];
			minpos = j;
		}
	}
	i--;

	int tmp = buf[i];
	buf[i] = buf[minpos];
	buf[minpos] = tmp;

	int a = i + 1;
	int b = len - 1;

	while (a < b) {
		int tmp = buf[a];
		buf[a] = buf[b];
		buf[b] = tmp;
		a++;
		b--;
	}
}

