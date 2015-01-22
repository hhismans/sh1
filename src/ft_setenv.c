/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:30:00 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/22 02:49:41 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh1.h"
#include <stdlib.h>

int		ft_setenv2(t_list *tmp2, char **tabarg, char *new_var_env)
{
	char	*tmpvar;

	while (tmp2)
	{
		tmpvar = getvar(tmp2->content);
		if (!ft_strcmp(tmpvar, tabarg[1]))
		{
			free(tmpvar);
			free(tmp2->content);
			tmp2->content = new_var_env;
			return (1);
		}
		free(tmpvar);
		tmp2 = tmp2->next;
	}
	return (0);
}

void	ft_envadd(t_list *env, char *new_var_env)
{
	while (env->next)
	{
		env = env->next;
	}
	env->next = ft_lstnew(new_var_env, ft_strlen(new_var_env) + 1);
}

void	ft_setenv(t_list **env, char **tabarg)
{
	char	*new_var_env;
	t_list	*tmp2;

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
		return ;
	}
	if (ft_setenv2(tmp2, tabarg, new_var_env))
		return ;
	else
		ft_envadd(*env, new_var_env);
}
