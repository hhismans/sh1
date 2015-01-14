/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:28:03 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/14 23:18:00 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"

t_func	g_tab[] =
{
	{&ft_env, "env"},
	{&ft_cd, "cd"},
	{&ft_setenv, "setenv"},
	{&ft_unsetenv, "unsetenv"},
	{NULL, NULL}
};

/*
** FUNCTION : find_env
** return the element "elem" in the env variable
** RETURN VALUE : char *
** the content of the elem (part after = ) or NULL if not found
*/
char	*find_in_env(char **env, char *elem)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (env[i])
	{
		if (ft_strfind(env[i], elem))
			break ;
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

void	inwhile(char **pathtab, char **tabarg)
{
	char	*rightpath;
	pid_t	father;

	if (!(rightpath = find_right_path(pathtab, tabarg[0])))
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

int		nbr_word_in_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int		case_builtin(char **tabarg, t_list **e)
{
	int i;

	i = 0;
	while (g_tab[i].key != NULL)
	{
		if (!strcmp(g_tab[i].key, tabarg[0]))
		{
			g_tab[i].ptrfunc(e, tabarg);
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	char	*path;
	char	**pathtab;
	char	**tabarg;
	t_list	*e;

	path = find_in_env(env, "PATH");
	pathtab = ft_strsplit(path, ':');
	e = tabtolist(env);
	while (1)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		tabarg = ft_strsplit(line, ' ');
		if (!case_builtin(tabarg, &e))
			inwhile(pathtab, tabarg);
		free(line);
	}
	return (argv - argv + argc - argc);
}
