/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:40:37 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/14 23:36:45 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft.h"

typedef struct	s_func
{
	void (*ptrfunc)(t_list **, char **);
	char *key;
}				t_func;

void			ft_env(t_list **env, char **tabarg);
void			ft_cd(t_list **env, char **tabarg);
void			ft_unsetenv(t_list **env, char **tabarg);
void			ft_setenv(t_list **env, char **tabarg);
char			*getvar(const char *str);
void			freelist(t_list *env);
char			*find_right_path(char **path, char *command);
char			**remove_tabelem(char **tab, int elem);
t_list			*tabtolist(char **tab);
int				nbr_word_in_tab(char **tab);
#endif
