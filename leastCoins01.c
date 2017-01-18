/*
 this is to find the minimum coins to make a given value, not make every value
 between a range

 method1: using recursion

 if V == 0, then 0 coins required
 if V > 0
    minCoin(coins[0..m-1], V) = min {1 + min(V-coins[i])}
                                where i varies from 0 to m-1
                                and coin[i] <= V
*/

#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int m, int V)
{
    if (V == 0) return 0;
    int res = INT_MAX;
    int i;
    for (i = 0; i < m; ++i) {
        if (coins[i] > V) {
            continue;
        }
        int sub_res = minCoins(coins, m, V - coins[i]);
        if (sub_res != -1 && res > 1 + sub_res)
            res = sub_res + 1;
    }
    if (res == INT_MAX)
        return -1;
    return res;
}

int main()
{
    int coins[] =  {1, 5, 15, 25};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 5;
    printf("Minimum coins required is %d\n", minCoins(coins, m, V));
    return 0;
}