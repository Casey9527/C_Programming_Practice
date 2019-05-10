
/*
 * Using enum to define various states rather than define.
 * In this way, enum will show as "strings" when debugging
 * under GDB.
 *
 * compile this program as: 
 * 	gcc -g enumDebug.c -o enumDebug.o
 *
 * examining steps:
 *
 * > gdb enumDebug.o
 * > (gdb) start
 * > (gdb) step
 * > (gdb) p oneApple
 *
 */

#include <stdio.h>

typedef enum {
	apple,
	banana,
	grape,
	mango,
	orange
} fruit;

void main(void) {
	fruit oneApple = apple;
	fruit oneBanana = banana;
	fruit oneGrape = grape;
	fruit oneMango = mango;
	fruit oneOrange = orange;
}
