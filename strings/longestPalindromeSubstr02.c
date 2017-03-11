void expand(char *s, int l, int r, int len, int *result) {
    while (l >= 0 && r <= len - 1 && s[l] == s[r]) {
        if (r - l + 1 > result[1]) {
            result[0] = l;
            result[1] = r - l + 1;
        }
        l --;
        r ++;
    }
}

char* longestPalindrome(char* s) {
    // edge cases
    if (!s) {
        return s;
    }
    int len = strlen(s);
    // expand the substring towards two sides using i or (i, i + 1) as center
    // result[0] stores the starting index, result[1] stores the max length
    int result[2] = {0, 1};
    int i;
    for (i = 0; i < len; i ++) {
        expand(s, i, i, len, result);
        expand(s, i, i + 1, len, result);
    }
    
    char *ret = (char *) malloc(result[1] + 1);
    int j = 0;

    for (i = result[0]; i < result[0] + result[1]; i ++) {
        ret[j ++] = s[i];
    }
    ret[j] = '\0';
    return ret;
}