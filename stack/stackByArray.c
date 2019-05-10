/*
 * Implement a stack using an array
 */

#define MAX_SIZE 100

struct stack{
	int sp;			/* Next available index */
	char e[MAX_SIZE];	/* Characters stack */
}s;

s.sp = 0;

void push(char *c)
{
	if (sp < MAX_SIZE){
		s.e[sp++] = c;
	} else {
		printf("error: stack is full cannot push %c\n", c);
	}
}

char pop(void)
{
	if (sp > 0) {
		return s.e[--sp];
	} else {
		printf("error: stack is empty\n");
		return EOF;
	}
}

char top(void)
{
	if (sp > 0)
		return s.e[sp - 1];
	else
		return EOF;
}
