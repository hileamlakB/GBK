#include "gbk.h"


static void handlerc(int);
inline void cmdmv(cmdnode **, int);
inline void xcmd(char *, alias **);


/**
 *main - main loop for the gbk shell
 *@argc: number of arguments
 *@argv: script file names
 *@argp: envrionmental variables
 *Return: returns the index of 0 on sucess
 */
int main(int argc, char **argv, char **argp)
{
	char *cmd = NULL, **cmds = NULL;
	size_t cmdlen = 0;
	int mode = !isatty(0), i = 0, cmdnum = 1;
	struct sigaction sa;
	alias *head = NULL;

	if (argc > 1)
	{
		runscript(argv[1]);
		exit(0);
	}
	(void)argp;

	sa.sa_handler = handlerc, sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		cmd = NULL, cmds = NULL, getinput(&cmd, &cmdlen, &cmds, mode ? 0 : 1);
		cmdnum = arlen(cmds), i = 0;
		free(cmd);
		while (i < cmdnum)
			xcmd(cmds[i], &head), i++;
		freedp(cmds);
		if (mode)
			write(1, "#cisfun$ ", 9), exit(255);
	}
	exit(EXIT_SUCCESS);
}


/**
 *handlerc - handlce SIGNUM
 *@signum: sig ID
 */
static void handlerc(int signum)
{
	write(1, "\n", 1);
	(void)signum;
}

/**
 *cmdmv - moves the command list to the next command
 *accorindign to the commands and the execute statues
 *of the current cmd
 *@head:a pointer to a pointer to the current commands
 *@childstat: the status of the execution of the current command
 *node
 */
inline void cmdmv(cmdnode **head, int childstat)
{

	if (!strcmp((*head)->op, "||"))
	{
		if (!childstat)
		{
			(*head)->op = (*head)->next->op;
			(*head)->next = (*head)->next->next;
			(*head)->estat = 1;
		}
		else
			(*head) = (*head)->next;

	}
	else if (!strcmp((*head)->op, "&&"))
	{
		if (!childstat)
			(*head)->estat = 1, (*head) = (*head)->next;
		else
		{
			(*head)->op = (*head)->next->op;
			(*head)->next = (*head)->next->next;
		}
	}
	else
		(*head) = (*head)->next;
}
/**
 *xcmd - parses, and uses the excute function
 *to creats a process and excute the cmd
 *@cmds: command
 *@aliashead: head of the laias list
 */
inline void xcmd(char *cmds, alias **aliashead)
{
	char **tmp = NULL;
	int childid;
	static int childstat;
	cmdnode *head = NULL, *_head = NULL;

	_head = build_list(cmds);
	head = _head;
	while (head)
	{
		strexpand(&(head->cmd), childstat);
		parseargs(head->cmd, " ", &tmp, 0);
		whistory(cmds);
		if (!handlebin(tmp, aliashead))
		{
			free_cmdlist(_head);
		return;
}
		if (head->estat == 0)
		{
			fflush(stdout);
			childid = fork();
			if (childid == 0)
				execute(tmp, cmds, _head);
			else
			{
				wait(&childstat);
				cmdmv(&head, childstat);
			}
		}
		else
		{
			if (!strcmp(head->op, "||"))
			{
				head->op = head->next->op;
				head->next = head->next->next;
			}
			else
				head = head->next;
		}
	}
	free_cmdlist(_head);
}
