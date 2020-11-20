#include "gbk.h"

/**
 * whistory - writes history of commands
 * @history: command to be stored in the history list
 * Return: 0 on success and 1 in faliure
 */
int whistory(char *history)
{
	char *filename, *h = getenv("HOME");
	char *tmp = NULL;
	ssize_t w, fd;
	int len = strlen(history);/* first = 0;*/


	filename = malloc(strlen(h) + strlen(".simple_shell_history") + 4);
	strcpy(filename, h), strcat(filename, "/.simple_shell_history");
	/*if (!stat(filename, &s))first = 1;*/
	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0640);
	free(filename);
	if (fd < 0)
		return (1);
	/*put the number of comments on the top*/
	/*
	 *	if (first)
	 *	{
	 *		w = read(fd, tmp, 1);
	 *		while (w > 0 && *history != '\n' )
	 *			w = read(fd, history, 1);
	 *		atoi(tmp);
	 *	}
	 */
	if (len)
	{
		tmp = malloc(len + 4);
		strcpy(tmp, history), strcat(tmp, "\n");
		w = write(fd, tmp, len + 1);
		if (w < 0)
		{
			close(fd);
			free(tmp);
			return (1);
		}
		free(tmp);
	}
	close(fd);
	return (0);
}


/**
 * phistory - prints histories
 * Return: 0 on success and 1 in faliure
 */
int phistory(void)
{
	char *filename, *h = getenv("HOME");
	char *history = calloc(4, 1);
	int fd, w = 1;
	int counter = 0;

	filename = malloc(strlen(h) + strlen(".simple_shell_history") + 4);
	strcpy(filename, h);
	strcat(filename, "/.simple_shell_history");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	while (w > 0)
	{
		counter++;
		w = read(fd, history, 1);
		if (w > 0)
			printf("   %i  ", counter);
		while (w > 0 && *history != '\n')
		{
			printf("%s", history);
			w = read(fd, history, 1);
		}
		if (w > 0 && *history == '\n')
			printf("\n");
	}
	free(filename);
	free(history);
	close(fd);
	return (1);
}
