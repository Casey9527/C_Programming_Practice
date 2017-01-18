#include <stdio.h>

int main() {
    
    int a = 3;
    int *ptr = &a;
    int **ptr_ref = &ptr;
    
    int ***ptr_ref_ref = &ptr_ref;
    
    printf("*ptr: %d\n", *ptr);
    printf("**ptr_ref: %d\n", **ptr_ref);
    printf("***ptr_ref_ref: %d\n", ***ptr_ref_ref);
    return 0;
}