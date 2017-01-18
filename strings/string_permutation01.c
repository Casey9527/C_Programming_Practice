#include <stdio.h>


void swap(char *s, int index1, int index2)
{
    char temp;
    temp = s[index1];
    s[index1] = s[index2];
    s[index2] = temp;
}

/**
 *  print_all_permutations - print out all permutations of input string @s
 * 
 *  @s:         input string
 *  @output:    store each output sequence in output
 *  @size:      input string size
 *  @pos:       index of first character to print out
 * 
 *  returns nothing.
 * */

void print_all_permutations(char *s, char *out, int size, int pos)
{
    // the last position
    if (pos == size - 1) {
        out[pos] = s[pos];
        printf("%s\n", out);
        return;
    }
    int i;
    for (i = pos; i < size; i ++) {
        // output s[i] at pos
        swap(s, pos, i);
        // output char at current pos
        out[pos] = s[pos];
        // output all permutations from (pos + 1)
        print_all_permutations(s, out, size, pos + 1);
        // backtracking
        swap(s, pos, i);
    }
}


int
main()
{
    char str[5] = "kexin";
    
    char out[5] = "";
    
    print_all_permutations(str, out, 5, 0);
    
    return 0;
}