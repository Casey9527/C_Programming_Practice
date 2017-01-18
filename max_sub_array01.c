


int max_sub_array(int[] a, int n)
{
    if (a == NULL || n == 0)
        return 0;
    
    int local = a[0];
    int global = a[0];
    
    for (i = 1; i < n; i ++) {
        // we discard the last local only 
        local  = max(local + a[i], a[i]);
        global = max(local, global);
        
    }
    
    return global;
}