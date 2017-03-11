
void nextPermutation(int* nums, int numsSize) {
    int last = nums[0];
    for (int i = numsSize - 1; i > 0; i--) {
        // 先找到一个可以使得字符串值增大的机会
        if (nums[i] > nums[i-1]) {
            // 从右往左找一个比这个点大的最小值
            int key = nums[i-1];
            
            int min = nums[i];
            int mini = i;

            // 法克！这里的要点是，找到最靠右的可替换值！！！！
            // 不然翻转之后就会出问题！！！！
            // 因此从左向右扫描并接受相等值！
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] <= min && nums[j] > nums[i-1]) {
                    min = nums[j];
                    mini = j;
                }
            }

            // 替换
            int tmp = nums[i-1];
            nums[i-1] = min;
            nums[mini] = tmp;
            
            // 翻转
            int a = i;
            int b = numsSize - 1;
            
            while (a < b) {
                int tmp = nums[a];
                nums[a] = nums[b];
                nums[b] = tmp;
                a++;
                b--;
            }

            return;
        }
    }
    
    int a = 0;
    int b = numsSize - 1;
    
    while (a < b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
        a++;
        b--;
    }
}
