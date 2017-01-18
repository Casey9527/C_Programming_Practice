/*
 this is to find the minimum coins to make a given value, not make every value
 between a range

 method 2: DP
 
*/

#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int m, int V)
{
    int table[V + 1];   // table[i] is the minimum number of coins for value i
    table[0] = 0;       // base case when V = 0
    int i, j;
    
    for (i = 1; i <= V; ++i)
        table[i] = INT_MAX;

    for (i = 1; i <= V; ++i) {
        for (j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub_res = table[i - coins[j]];
                if (sub_res != -1 && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
        }
        if (table[i] == INT_MAX)    // to make sense. 
            table[i] = -1;          // -1 means cannot make that value
    }
    return table[V];
}

int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    printf("Minimum coins required is %d\n", minCoins(coins, m, V));
    return 0;
}