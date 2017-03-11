/*  no extra data structure is used
 *  runtime O(n^2)
 *  after dups removed, the following elements must be shifted forward
 *  don't require to sort the array
 *  
 */

void rmDups(int a[], int n)
{
    int i;
    int current, end;
    
    current = 1;
    end = n - 1;
    
    for (i = 0; i < end; i++) {
        current = i + 1;
        while (current <= end) {
            if (a[current] == a[i]) {
                a[current] = a[end];
                end--;
            } else {
                current++;
            }
        }
    }
}