/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:29:10 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/22 11:36:40 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh1.h"

void	ft_unsetenv2(t_list *env, char **tabarg)
{
	t_list	*ltmp;
	char	*ctmp;

	ltmp = (env);
	(env) = (env)->next;
	while (env)
	{
		ctmp = getvar((env)->content);
		if (!strcmp(ctmp, tabarg[1]))
		{
			ltmp->next = (env)->next;
			freelist(env);
			break;
		}
		ltmp = (env);
		env = (env)->next;
	}
}

void	ft_unsetenv(t_list **env, char **tabarg)
{
	t_list	*ltmp;
	char	*ctmp;
	t_list	*tmp;

	if (nbr_word_in_tab(tabarg) != 2)
	{
		ft_putendl("Wrong number of argument: unsetenv");
		return ;
	}
	tmp = *env;
	ctmp = getvar((*env)->content);
	if (!strcmp(ctmp, tabarg[1]))
	{
		ltmp = (*env);
		*env = ltmp->next;
		freelist(ltmp);
		return ;
	}
	ft_unsetenv2(*env, tabarg);
	*env = tmp;
}
