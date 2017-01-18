/*
    solve josephus problem in O(n)
    use both iterative and recursive
*/

#include <stdio.h>

int jos_iterative(int n, int k)
{
    int i, m = 0;
    for (i = 1; i <= n; ++i)
        m = (m + k) % i;
    return m;
}

int jos_recursive(int n, int k)
{
    if (n == 1) return 0;
    return (k + jos_recursive(n - 1, k)) % n;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    
    printf("%d\n", jos_iterative(n, k) + 1);
    printf("%d\n", jos_recursive(n, k) + 1);
    
    return 0;
}