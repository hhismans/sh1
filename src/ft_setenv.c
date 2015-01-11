/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:30:00 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 10:36:45 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh1.h"
#include <stdlib.h>

void	ft_setenv(t_list **env, char **tabarg)
{
	char *tmpvar;
	char *new_var_env;
	t_list *tmp;
	t_list *tmp2;

	tmp2 = *env;
	if (nbr_word_in_tab(tabarg) != 3)
	{
		ft_putendl("Wrong number of argument: setenv");
		return ;
	}
	new_var_env = ft_strjoin(tabarg[1], "=");
	ft_strrealloc((char **)&(new_var_env), tabarg[2]);
	if (tmp2 == NULL)
	{
		tmp2 = ft_lstnew(new_var_env, ft_strlen(new_var_env) + 1);
		free(new_var_env);
		return;
	}
	while (tmp2)
	{
		tmpvar = getvar(tmp2->content);
		if (!ft_strcmp(tmpvar, tabarg[1]))
		{
			free(tmpvar);
			free(tmp2->content);
			tmp2->content = new_var_env;
			return ;
		}
		free(tmpvar);
		tmp = tmp2;
		tmp2 = tmp2->next;
		ft_putendl("salut");
	}
	tmp->next = ft_lstnew(new_var_env, ft_strlen(new_var_env) + 1);
}
