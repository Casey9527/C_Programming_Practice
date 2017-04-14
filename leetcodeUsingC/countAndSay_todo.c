// 11:53 am - 12:28 am


/**
 *
 * leetcode 38
 *
 * todo: fix the resize issue in C
 *       currently the program broken when n >= 14
 *
 **/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* countAndSay(int n) {
    // edge case
    if (n <= 0) {
        return NULL;
    }
    if (n == 1) {
        return "1";
    }
    
    char *ret = (char *) calloc(sizeof(char), 2 * n + 1);
    if (!ret) {
        printf("malloc failed\n");
        exit(1);
    }
    
    char *tmp = (char *) calloc(sizeof(char), 2 * n + 1);
    if (!tmp) {
        printf("malloc failed\n");
        exit(1);
    }
    
    tmp[0] = '1';
    
    int i;
    char *cur, *next;
    int k = 0;
    int count;
    
    for (i = 1; i < n; i ++) {
        cur = tmp;
        while (*cur != '\0') {
            count = 1;
            next = cur + 1;
            while (*next != '\0' && *cur == *next) {
                next ++;
                count += 1;
            }
            if (k == 2 * n) {   // resize;
                ret = realloc(ret, 2 * n * 2 + 1);
                tmp = realloc(tmp, 2 * n * 2 + 1);
            }
            ret[k ++] = count + '0';
            
            if (k == 2 * n) {   // resize;
                ret = realloc(ret, 2 * n * 2 + 1);
                tmp = realloc(tmp, 2 * n * 2 + 1);
            }
            ret[k ++] = *cur;
            
            cur = next;
        }
        int m;
        for (m = 0; m < strlen(ret); m ++) {
            tmp[m] = ret[m];
        }
        k = 0;
    }

    free(tmp);
    return ret;
}

void main(int ac, char *av[])
{
    if (ac != 2) {
        printf("USAGE: ./countAndSay n\n");
        return;
    }
    char *ret;
    ret = countAndSay(atoi(av[1]));
    printf("%s\n", ret);
}