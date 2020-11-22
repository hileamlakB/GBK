#include "gbk.h"
/**
 *_putenv - addes es to environ
 *@es: environmnetal varibale value pair
 *Return: 0 on secuss and -1 on faliure
 */
int _putenv(char *es)
{

	char **_environ = environ, **newenviron, **_newenviron;
	int len = 0;

	while (*_environ)
		len++, _environ++;
	/*one for the new variable and the other for the null*/
	newenviron = smalloc(sizeof(char *) * (len + 2));
	_newenviron = newenviron;
	_environ =  environ;
	while (len)
	{
		*_newenviron = smalloc(sizeof(char) * strlen(*_environ));
		strcpy(*_newenviron, *_environ);
		_newenviron++, _environ++, len--;
	}
	*_newenviron = smalloc(sizeof(char) * strlen(es));
	strcpy(*_newenviron, es);
	_newenviron++;
	*_newenviron = NULL;
	environ = newenviron;
	return (0);
}

/**
 *_setenv - addes es to environ if it doesn't already
 *exist or overwrite is enabled
 *@name: variable name
 *@value: value
 *@overwrite: overwrite status
 *Return: 0 on secuss and -1 on faliure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *es;

	if (name == NULL || name[0] == '\0' || value == NULL)
		return (-1);

	if (getenv(name) != NULL && overwrite == 0)
		return (0);
	if (overwrite)
		_unsetenv(name);

	es = smalloc(strlen(name) + strlen(value) + 2);
	/* +2 for '=' and null terminator */
	if (es == NULL)
		return (-1);

	strcpy(es, name);
	strcat(es, "=");
	strcat(es, value);

	return ((_putenv(es) != 0) ? -1 : 0);
}

/**
 *_unsetenv - removes a variable from the environ list
 *@name: name of varaible
 *Return: 0 on secuss and -1 on faliure
 */
int _unsetenv(const char *name)
{
	char **ep, **sp;
	size_t len;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);

	len = strlen(name);

	for (ep = environ; *ep != NULL; )
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
			/*
			*Remove found entry by shifting
			*all successive entries back one element
			*/
			for (sp = ep; *sp != NULL; sp++)
				*sp = *(sp + 1);
		else
			ep++;

	return (0);
}

/**
 *_printenv - prints environmental variables
 **/
void _printenv(void)
{
	char **_env = environ;

	while (*_env)
	{
		printf("%s\n", *_env);
		_env++;
	}
}


