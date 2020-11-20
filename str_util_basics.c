#include "gbk.h"

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	int length = strlen(s);
	int counter = 0;
	char tmp;

	while (counter < length / 2)
	{
		tmp = *(s + counter);
		*(s + counter) = *(s + length - 1 - counter);
		*(s + length - 1 - counter) = tmp;
		counter++;
	}

}

