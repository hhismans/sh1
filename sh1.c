/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:28:03 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/08 04:07:07 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
** FUNCTION : find_env
** return the element "elem" in the env variable
** RETURN VALUE : char *
** the content of the elem (part after = ) or NULL if not found
*/
char *find_in_env(char **env, char *elem)
{
	int i;
	int j;
	char *path;

	i = 0;
	while (env[i])
	{
		if(ft_strfind(env[i], elem))
			break;
		i++;
	}
	if (!env[i])
		return (NULL);
	j = 0;
	while (env[i][j] != '=')
		j++;
	path = ft_strdup(&(env[i][j + 1]));
	return (path);
}

/*
** FUNCTION : find_right_path
** return the right path to find the bin "command"
** RETURN VALUE : char *
** char * to the right string, or NULL if not find
*/
char	*find_right_path(char **path, char *command)
{
	int i;
	char *ret;

	i = 0;
	while (path[i])
	{
		ret = ft_strjoin(path[i], "/");
		ft_strrealloc(&ret, command);
		if (!access(ret, X_OK))
			return(ret);
		free(ret);
		i++;
	}
	return (NULL);
}

char	**remove_tabelem(char **tab, int elem)
{
	int i;
	int j;
	char **ret;
	int size;

	size = 0;
	while (tab[size])
		size++;
	ret = (char **)malloc(sizeof(char *) * size);
	i = 0;
	j = 0;
	free(tab[i]);
	while (tab[i + 1])
	{
		if (i != elem)
		{
			ret[j] = ft_strdup(tab[i]);
			free(tab[i + 1]);
			j++;
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

t_list	*tabtolist(char **tab)
{
	int i;
	t_list *env;
	t_list *tmp;

	env = ft_lstnew(tab[0], ft_strlen(tab[0]) + 1);
	i = 1;
	tmp = env;
	while (tab[i])
	{
		tmp->next = ft_lstnew(tab[i], strlen(tab[0]) + 1);
		i++;
		tmp = tmp->next;
	}
	return (env);
}

void	inwhile(char **pathtab, char *line)
{
		char	*rightpath;
		char	**tabarg;
		pid_t	father;

		tabarg = ft_strsplit(line, ' ');
		if(!(rightpath = find_right_path(pathtab, tabarg[0])))
		{
			ft_putstr("minishell: command not found : ");
			ft_putendl(tabarg[0]);
		}
		else
		{
			father = fork();
			if (father > 0)
				wait(NULL);
			if (father == 0)
			{
				execve(rightpath, tabarg, NULL);
			}
		}
}

int		main(int argc, char **argv, char **env)
{
	char *line;
	char *path;
	char **pathtab;
	t_list *e;

	path = find_in_env(env, "PATH");
	pathtab = ft_strsplit(path, ':');
	e = tabtolist(env);
	while (1)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		inwhile(pathtab, line);
		free(line);
	}
	return (argc - argc +argv - argv);
}
