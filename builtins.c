#include "gbk.h"


/**
 *handlebin - handles builtin commands
 *@cmd: command arguements
 *@head: head of the alias list
 *Return: 0 if builting commond executed or 1 if not
 */
int handlebin(char **cmd, alias **head)
{
	int exitstatus = 0, rvalue = 1;

	if (!strcmp(cmd[0], "exit"))
	{
		if (cmd[1])
			exitstatus = atoi(cmd[1]);
		freedp(cmd), exit(exitstatus);
	}
	else if (!strcmp(cmd[0], "env") || !strcmp(cmd[0], "printenv"))
		_printenv(), rvalue = 0;
	else if (!strcmp(cmd[0], "\n"))
		rvalue = 0;
	else if (!strcmp(cmd[0], "setenv"))
	{
		if (arlen(cmd) != 3)
			fprintf(stderr, "Too few or too many arguements\n");
		_setenv(cmd[1], cmd[2], 0), rvalue = 0;
	}
	else if (!strcmp(cmd[0], "unsetenv"))
	{
		if (arlen(cmd) != 2)
			fprintf(stderr, "Too few or too many arguements\n");
		_unsetenv(cmd[1]), rvalue = 0;
	}
	else if (!strcmp(cmd[0], "cd"))
		_chdir(arlen(cmd) > 1 ? cmd[1] : NULL),	rvalue = 0;
	else if (!strcmp(cmd[0], "history"))
		phistory(), rvalue = 0;
	else if (!strcmp(cmd[0], "help"))
		phelp(arlen(cmd) > 1 ? cmd[1] : NULL),	rvalue = 0;
	else if (!strcmp(cmd[0], "alias"))
		handle_alias(cmd, head), rvalue = 0;

	if (!rvalue)
		freedp(cmd);
	return (rvalue);
}
