y = x & (-x);

/*
-x equals (~x + 1)

x : bn..bi+1 bi bi-1 .. b0
-x:
 bn..bi+1 are inverted
 bi remain unchanged
 bi-1..b0 becomes all zeros
*/
