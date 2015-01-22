/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:28:28 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/22 03:22:36 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"

char		*find_in_env_l(t_list *env, char *elem)
{
	int		j;
	char	*path;

	while (env)
	{
		if (ft_strfind(env->content, elem))
			break ;
		env = env->next;
	}
	if (!env)
		return (NULL);
	j = 0;
	while (((char *)(env->content))[j] != '=')
		j++;
	path = ft_strdup(&(((char *)(env->content))[j + 1]));
	return (path);
}

void		ft_setpwd(t_list **env, char **tab)
{
	size_t	i;
	char	*pwd;

	i = 1;
	pwd = ft_memalloc(1);
	while (!(getcwd(pwd, i)))
	{
		i++;
		free(pwd);
		pwd = ft_memalloc(i);
	}
	tab[1] = "PWD";
	tab[2] = ft_strdup(pwd);
	free(pwd);
	ft_setenv(env, tab);
}

void		ft_cd(t_list **env, char **tabarg)
{
	char **tab;

	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("steenv");
	tab[1] = ft_strdup("OLDPWD");
	tab[2] = find_in_env_l(*env, "PWD");
	tab[3] = NULL;
	chdir(tabarg[1]);
	ft_setenv(env, tab);
	ft_setpwd(env, tab);
	free(tab);
}
