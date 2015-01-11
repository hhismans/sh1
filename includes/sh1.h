/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:40:37 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 07:06:01 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_h
#define SH1_h

#include "libft.h"

typedef struct	s_func
{
	void (*ptrfunc)(t_list **, char **);
	char *key;
}				t_func;


void	ft_env(t_list **env, char **tabarg);
void	ft_cd(t_list **env, char **tabarg);
void	ft_unsetenv(t_list **env, char **tabarg);
void	ft_setenv(t_list **env, char **tabarg);
char	*getvar(const char *str);
#endif
