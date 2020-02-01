/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int m = matrixSize;
    int n = matrixColSize[0];
    int index = 0;

    int k = 0;
    int *ret = malloc(sizeof(int) * m * n);
    memset(ret, 0, sizeof(int) * m * n);
    *returnSize = m * n;

    while (true) {
        // 右
        for (int i=k; i<n-k; i++) {
            ret[index++] = matrix[k][i];
            if (index == *returnSize) return ret;
        }

        // 下
        for (int i=k+1; i<m-k; i++) {
            ret[index++] = matrix[i][n-k-1];
            if (index == *returnSize) return ret;
        }

        // 左
        for (int i=n-k-2; i>=k; i--) {
            ret[index++] = matrix[m-1-k][i];
            if (index == *returnSize) return ret;
        }

        // 上
        for (int i=m-k-2; i>=k+1; i--) {
            ret[index++] = matrix[i][k];
            if (index == *returnSize) return ret;
        }
        k++;
    }

    return ret;
}
