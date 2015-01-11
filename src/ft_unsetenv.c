/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:29:10 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 09:29:38 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh1.h"

void	ft_unsetenv(t_list **env, char **tabarg)
{
	t_list *ltmp;
	char	*ctmp;
	t_list *tmp;

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
	while (*env)
	{
		ctmp = getvar((*env)->content);
		if (!strcmp(ctmp, tabarg[1]))
		{
			ft_putendl((*env)->content);
			ltmp->next = (*env)->next;
			freelist(*env);
		}
		ltmp = (*env);
		*env = (*env)->next;
	}
	*env = tmp;
}
