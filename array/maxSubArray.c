


int max_sub_array(int[] a, int n)
{
    if (a == NULL || n == 0)
        return 0;
    
    int local = a[0];
    int global = a[0];
    
    for (i = 1; i < n; i ++) {
        if (local <= 0) {   // discard the previous local
            local = a[i];   // when it is less than 0
        } else {
            local = local + a[i];
        }

        if (global < local) {
            global = local;
        }
    }
    
    return global;
}