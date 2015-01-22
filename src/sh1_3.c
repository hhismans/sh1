/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 03:18:27 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/22 04:11:42 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"

char	**up_env(t_list *e)
{
	char	**env;
	int		i;
	int		nbr_elemt;
	t_list	*tmp;

	nbr_elemt = 0;
	tmp = e;
	while (tmp)
	{
		tmp = tmp->next;
		nbr_elemt++;
	}
	env = (char **)malloc(sizeof(char *) * nbr_elemt + 1);
	i = 0;
	tmp = e;
	while (tmp)
	{
		env[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	env[nbr_elemt] = NULL;
	return (env);
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

void	freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	trimtabarg(char **tabarg)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tabarg[i])
	{
		tmp = tabarg[i];
		tabarg[i] = ft_strtrim(tabarg[i]);
		free(tmp);
		i++;
	}
}
