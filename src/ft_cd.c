/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:28:28 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 14:58:19 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*find_in_env_l(t_list *env, char *elem)
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

void	ft_cd(t_list **env, char **tabarg)
{
	char **tab;

	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("steenv");
	tab[1] = ft_strdup("OLDPWD");
	tab[2] = find_in_env_l(*env, "PWD");
	tab[3] = NULL;
	int i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
	if (chdir(tabarg[1]) == 0)
		return (0);
	if (!strcmp tabarg[1] "..")
	ft_setenv(env, tab);
}

