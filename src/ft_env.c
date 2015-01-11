/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:27:20 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 11:10:35 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_env(t_list **env, char **tabarg)
{
	t_list	*tmp;

	tmp = *env;
	if (tabarg[0][0] == 'e')
	{
		while (tmp)
		{
			ft_putendl((tmp)->content);
			tmp = tmp->next;
		}
	}
}
