/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:28:03 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/07 21:06:50 by hhismans         ###   ########.fr       */
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

int main(int argc, char **argv, char **env)
{
	char *line;
	char *path;
	char **pathtab;
	char *rightpath;

	argc = (int)argc;
	argv = (char **)argv;
	path = find_in_env(env, "PATH");
	pathtab = ft_strsplit(path, ':');
	while (1)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		if(!(rightpath = find_right_path(pathtab, line)))
			ft_putendl("minishell : Command not found :");
		else
			ft_putendl(rightpath);
		free(line);
	}
	return (0);
}
