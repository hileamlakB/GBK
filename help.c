#include "help.h"

/**
*phelp - prints help for arg
*@arg: string whose pirnt to be printed
*/
void phelp(char *arg)
{
	if (!arg)
		printf(ghelp);
	else if (!strcmp(arg, "help"))
		printf(help_h);
	else if (!strcmp(arg, "set"))
		printf(set_h);
	else if (!strcmp(arg, "unset"))
		printf(unset_h);
	else if (!strcmp(arg, "history"))
		printf(history_h);
	else if (!strcmp(arg, "env"))
		printf(env_h);
	else if (!strcmp(arg, "cd"))
		printf(cd_h);
	else if (!strcmp(arg, "alias"))
		printf(alias_h);
	else if (!strcmp(arg, "exit"))
		printf(exit_h);
	else
		printf("No help found for %s", arg);
}
