#include "gbk.h"

/**
 *_getline - gets a line of string from a file
 *@lnptr: variable to store string
 *@size: number of things stored
 *@fd: file stream to read from
 *Return: the lenghh of lnptr or -1 on failure
 */
int _getline(char **lnptr, size_t *size, int fd)
{
	int in = 0, aloc = 0, x;
	char *_lnptr = NULL, *tmp;

	*lnptr = malloc(sizeof(char) * 3);
	if (!*lnptr)
		return (-1);
	aloc = 3, _lnptr = *lnptr;
	while (1)
	{
		if (in >= (aloc - 1))
		{
			aloc += 3, *lnptr = realloc(*lnptr, sizeof(char) * aloc);
			if (!*lnptr)
				return (-1);
			_lnptr = *lnptr + in;
		}
		tmp = malloc(sizeof(char) * 1),	x = read(fd, tmp, 1);
		if (x == 0)
			exit(0);
		if (x < 0 && errno == EINTR)
		{
			free(tmp);
			**lnptr = '\n',	*(*lnptr + 1) = '\n', *size = 2, in = 2;
			return (in);
		}
		if (x < 0)
			free(tmp), exit(-1);
		if (*tmp == '\n')
		{
			*_lnptr = '\n', *size += 1, in += 1;
			/*handle inputs like \n*/
			if (**lnptr == '\n')
				*_lnptr++ = '\n', *size += 1, in += 1;
			free(tmp);
			return (in);
		}
		*_lnptr = *tmp, in += 1, _lnptr += 1, *size = in;
		free(tmp);
	}
	return (in);
}

/**
 *_strcmpd - A special compare function that compares if one char
 * inside the sub string is equal to the first char of fstring
 *@fstring: fstring
 *@sub: subset
 *Return: 1 on success and -1 on faliur
 */
int _strcmpd(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (strlen(fstring) < strlen(sub))
		return (-1);
	while (*sub)
	{
		if (*sub == *fstring)
			return (1);
		sub++;
	}
	return (-1);

}
/**
 *_strcmps - A special compare function that compares if part of a string
 * inside the sub char is equal to the second string
 *@fstring: fstring
 *@sub: subset
 *Return: 1 on success and -1 on faliur
 */
int _strcmps(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (strlen(fstring) < strlen(sub))
		return (-1);
	while (*sub && *fstring)
	{
		if (*sub != *fstring)
			return (-1);
		sub++, fstring++;
	}
	return (1);

}

/**
 * _strtok - tokenizes a string according to a certain delimiter
 * it doesnt creat a new string to hold the tokens but rather creats a
 * a static variable that will directly copy str and puts the null
 * terminator everytime it finds the delimeter, the default str will be
 * manipulated so beware
 * for example if you have a string str = "helo; now; bo"
 * when _strtok is called for the first time (_strtok(str, ";")) it will put
 * \0 (a null terminator in the first location of the delimeter so the str
 * variable will be "helo\0 nowo; bo", ";" and it will be returned and the
 * static variable save would hold " nowo; bo" and when _strtok is called
 * for the second time _strtok(NULL, ";"); the same cyle continue
 * but this time instead of str save will be manipulated. This
 *cycle continues untile save == NULL
 * @str: the string to be tokenized
 * @delimeter: the delimiter to separate tokens
 * @whichf: which comparign funcion to use, 0 for strcmpd, and 1 for strcmps
 * Return: a character pointer to the current delimited token
 */
char *_strtok(char *str, const char *delimeter, int whichf)
{
	static char *save;
	char *_new = NULL;
	int i = 0, (*func)(char *, const char *), loc;

	func = (whichf == 0) ? _strcmpd : _strcmps;
	loc = (whichf) ? strlen(delimeter) - 1 : 0;

	if (!str || !*str)
	{
		if (!save || !*save)
			return (NULL);

		while (func(save + i, delimeter) != 1 && *(save + i) != '\0')
			i++;
		if (*(save + i) == '\0')
		{
			_new = save, save = NULL;
			return (_new);
		}
		_new = save;
		*(save + i) = '\0';
		save = save + i + loc + 1;

		return (_new);

	}
	while (func(str + i, delimeter) != 1 && *(str + i) != '\0')
		i++;

	if (*(str + i) == '\0')
		return (str);

	save = str + i + loc + 1;
	*(str + i) = '\0';
	return (str);
}
