

bool isValid(char* s) {
    int pstack[10000];
    int n = -1;
    char ch;
    
    while (ch = *s++) {
        switch (ch) {
            case '(':
                pstack[++n] = ch + 1;
                break;
            case '{': case '[':
                pstack[++n] = ch + 2;
                break;
            case ')': case '}': case ']':
                if (n == -1) return false;
                if (pstack[n] != ch) return false;
                n--;
                break;
        }
    }
    
    return n == -1;
}
