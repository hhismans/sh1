/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:29:10 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 11:09:22 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh1.h"

void	ft_unsetenv2(t_list *env, char **tabarg)
{
	t_list	*ltmp;
	char	*ctmp;

	while (env)
	{
		ctmp = getvar((env)->content);
		if (!strcmp(ctmp, tabarg[1]))
		{
			ltmp->next = (env)->next;
			freelist(env);
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

	tmp = *env;
	ctmp = getvar((*env)->content);
	if (!strcmp(ctmp, tabarg[1]))
	{
		ltmp = (*env);
		*env = ltmp->next;
		freelist(ltmp);
		return ;
	}
	ltmp = (*env);
	(*env) = (*env)->next;
	ft_unsetenv2(*env, tabarg);
	*env = tmp;
}
