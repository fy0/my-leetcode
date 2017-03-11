/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
// ³¬Ê±ÏÌÓã½â
 
#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

int match(char *s, int len1, char *m, int len2) {
    int i = 0;
    if (len2 > len1) return 0;
    int len = min(len1, len2);
    while ((i < len) && (s[i] == m[i])) {
        i++;
    }
    return (i == len2) ? len2 : 0;
}

int loopMatch(char *s, int len, char** words, int wordsSize, int len2) {
    int save[30000];
    int saven = 0;
    if (len2 * wordsSize > len) return 0;

    for (int i = 0; i < wordsSize; ++i) {
        int found = 0;
        for (int j = 0; j < wordsSize; ++j) {
            for (int x = 0; x < saven; ++x) {
                if (j == save[x]) goto _next_word;
            }
            int val = match(s, len, words[j], len2);
            if (val) {
                save[saven++] = j;
                s += val;
                len -= len2;
                found = 1;
                break;
            }
        _next_word:;
        }
        if (!found) return 0;
    }
    return 1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    if (wordsSize == 0) return NULL;
    int len1 = strlen(s);
    int len2 = strlen(words[0]);
    int *ret = (int*)malloc(1000 * sizeof(int));
    int n = 0;
    if (len2 * wordsSize > len1) return NULL;

    for (int i = 0; i < len1; ) {
        int val = loopMatch(s + i, len1 - i, words, wordsSize, len2);
        if (val) {
            ret[n++] = i;
            //i += wordsSize * len2;
            i += 1;
        } else i++;
    }
    *returnSize = n;
    return ret;
}
