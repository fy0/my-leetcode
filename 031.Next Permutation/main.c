
void nextPermutation(int* nums, int numsSize) {
    int last = nums[0];
    for (int i = numsSize - 1; i > 0; i--) {
        // ���ҵ�һ������ʹ���ַ���ֵ����Ļ���
        if (nums[i] > nums[i-1]) {
            // ����������һ�������������Сֵ
            int key = nums[i-1];
            
            int min = nums[i];
            int mini = i;

            // ���ˣ������Ҫ���ǣ��ҵ���ҵĿ��滻ֵ��������
            // ��Ȼ��ת֮��ͻ�����⣡������
            // ��˴�������ɨ�貢�������ֵ��
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] <= min && nums[j] > nums[i-1]) {
                    min = nums[j];
                    mini = j;
                }
            }

            // �滻
            int tmp = nums[i-1];
            nums[i-1] = min;
            nums[mini] = tmp;
            
            // ��ת
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
