/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:15:11 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/22 06:55:06 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"

/*
** /!\ Malloc use /!\
** FUNCTION : find_right_path
** return the right path to find the bin "command"
** RETURN VALUE : char *
** char * to the right string, or NULL if not find
*/
char	*find_right_path(char **path, char *command)
{
	int		i;
	char	*ret;

	i = 0;
	while (path[i])
	{
		ret = ft_strjoin(path[i], "/");
		ft_strrealloc(&ret, command);
		if (!access(ret, X_OK))
			return (ret);
		free(ret);
		i++;
	}
	return (NULL);
}

char	**remove_tabelem(char **tab, int elem)
{
	int		i;
	int		j;
	char	**ret;
	int		size;

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
	int		i;
	t_list	*env;
	t_list	*tmp;

	env = ft_lstnew(tab[0], ft_strlen(tab[0]) + 1);
	i = 1;
	tmp = env;
	while (tab[i])
	{
		tmp->next = ft_lstnew(tab[i], strlen(tab[i]) + 1);
		i++;
		tmp = tmp->next;
	}
	return (env);
}
