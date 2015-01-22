/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:28:03 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/22 12:35:48 by hhismans         ###   ########.fr       */
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
**FUNCTION : find_env
**return the element "elem" in the env variable
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

void	fork_and_exe(char **tabarg, char **env, char *rightpath)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		execve(rightpath, tabarg, env);
	}
}

void	inwhile(char **tabarg, t_list *e)
{
	char	*rightpath;
	char	*path;
	char	**env;
	char	**pathtab;

	env = up_env(e);
	pathtab = NULL;
	if ((path = find_in_env(env, "PATH")))
		pathtab = ft_strsplit(path, ':');
	if (tabarg[0][0] == '/')
		case_path(tabarg, env);
	else
	{
		if (!pathtab || !(rightpath = find_right_path(pathtab, tabarg[0])))
		{
			ft_putendl(tabarg[0]);
			ft_putendl(path);
			ft_putstr("minishell: command not found : ");
			ft_putendl(tabarg[0]);
		}
		else
			fork_and_exe(tabarg, env, rightpath);
	}
	free(path);
	freetab(pathtab);
	freetab(env);
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
	char	**tabarg;
	t_list	*e;
	char	*tmp;

	e = tabtolist(env);
	while (1)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		tmp = line;
		line = ft_strtrim(line);
		free(tmp);
		tabarg = ft_strsplit_blank(line);
		trimtabarg(tabarg);
		if (tabarg[0])
		{
			if (!(strcmp("exit", tabarg[0])))
				exit(0);
			if (!case_builtin(tabarg, &e))
				inwhile(tabarg, e);
			free(line);
		}
	}
	return (argv - argv + argc - argc);
}
