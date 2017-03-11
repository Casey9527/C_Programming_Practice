#include <stdio.h>

void reverse_str(char *begin, char *end)
{
	char tmp;
	while (begin < end) {
		tmp = *begin;
		*begin++ = *end;
		*end-- = tmp;
	}
}

void reverse_words(char *s)
{
	char* word_begin = s;
	char* cur   = s; // cur is for word boundary

	while (*cur) {
		cur ++;
		if (*cur == '\0') {
			reverse_str(word_begin, cur - 1);
		} else if (*cur == ' ') {
			reverse_str(word_begin, cur - 1);
			word_begin = cur + 1;
		}
	}
	reverse_str(s, cur - 1);
}
