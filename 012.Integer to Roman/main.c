char* intToRoman(int num) {
    int n = 0;
    char *buf = (char*)malloc(50);
    
    int split[] = { 0, 1, 5, 10, 50, 100, 500, 1000 };
    int sign[] = { '\0', 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    int sstart = sizeof(split) / sizeof(int) - 1;
    int si = sstart;

    while (si) {
        if (num < 100 && num >= 90) {
            buf[n++] = 'X';
            buf[n++] = 'C';
            num -= 90;
        } else if (num < 1000 && num >= 900) {
            buf[n++] = 'C';
            buf[n++] = 'M'; // Ìæ´úDCD
            num -= 900;
        } else {
            int count = num / split[si];
    
            if ((count > 1) && si != sstart && (count + 1) * split[si] == split[si + 1]) {
                buf[n++] = sign[si];
                buf[n++] = sign[si + 1];
            } else {
                for (int i = 0; i < count; ++i) {
                    buf[n++] = sign[si];
                }
            }
        }

        num %= split[si];
        if ((si == 2 || si == 3) && num == split[si] - 1) {
            buf[n++] = 'I';
            buf[n++] = sign[si];
            break;
        }
        si--;
    }

    buf[n] = '\0';
    return buf;
}
