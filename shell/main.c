#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char *line;

	line = readline("horse: ");
	printf("hiiii %s i", line);
	if (*line != '\0')
		add_history(line);
}
