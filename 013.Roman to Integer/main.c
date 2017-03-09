/*
table:
a = [0] * (ord('X') + 1)
a[ord('X')] = 10
a[ord('V')] = 5
a[ord('I')] = 1
a[ord('L')] = 50
a[ord('C')] = 100
a[ord('D')] = 500
a[ord('M')] = 1000

62 ms
63.56%
LeetCode 的计时基本不准，过了就行了。
*/

int romanToInt(char* s) {
    int table[] = {
        -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10
    }; 

    char *p = s;
    int num = table[*p], ret = 0;

    while (true) {
        int newnum = table[*p++];
        if (newnum == -1) break;
        if (newnum <= num) ret += newnum;
        else ret += newnum - num - num;
        num = newnum; 
    }
    return ret;
}
