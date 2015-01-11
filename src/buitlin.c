/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 03:55:42 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 10:57:25 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*getvar(const char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	ret = ft_strndup(str, i);
	return (ret);
}

void		freelist(t_list *env)
{
	free(env->content);
	free(env->next);
	free(env);
}
