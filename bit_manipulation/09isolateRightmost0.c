// It finds the rightmost 0-bit, turn off all bits, and set this
// bit to 1 in the result
y = ~x & (x + 1);

invert all bits: all bits inverted

x + 1: 
like 0011 -> 0100, the rightmost 0 becomes 1, 
its right part becomes all zero.