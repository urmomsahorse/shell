//#include "minishell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strchr(char *str, char c,char **arr)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
//	if (str[i] == '\0')
//		free(arr); //proper recursive free
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= strlen(s))
		return (strdup(""));
	if (len >= strlen(s) - start)
		len = strlen(s) - start;
	sub = (char *)malloc(len + 1 * sizeof(char));
	if (sub == NULL)
		return (NULL);
	if (start <= strlen(s))
		strlcpy(sub, s + start, len + 1);
	return (sub);
}

char **organize(char *str)
{
	char **arr;
	int pos;
	int start;
	int i;

	pos = 0;
	start = 0;
	i = 0;
	arr = malloc(sizeof(char *));
	while(str[pos] != '\0')
	{
		while(str[pos] == ' ' && str[pos] != '\0')
			pos++;
		start = pos;
		while (str[pos] != ' ' && str[pos] != '\0')
		{
			if (str[pos] == '"' || str[pos] == ',') //change to single comilla
				pos = pos + ft_strchr(&str[pos + 1], str[pos], arr);	
			pos++;
		}
		arr[i] = ft_substr(str, start, pos - start + 1); // suspicious; iterator?
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int main()
{
	char **res;

	res = organize("echo hi im horse");
	while (res != NULL)
	{
		printf("%s\n", *res);
		res++;
	}
}
