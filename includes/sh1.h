/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:40:37 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/22 10:04:19 by hhismans         ###   ########.fr       */
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
void			freetab(char **tab);
void			ft_cd(t_list **env, char **tabarg);
void			ft_unsetenv(t_list **env, char **tabarg);
void			ft_setenv(t_list **env, char **tabarg);
char			*getvar(const char *str);
void			freelist(t_list *env);
char			*find_right_path(char **path, char *command);
char			**remove_tabelem(char **tab, int elem);
t_list			*tabtolist(char **tab);
int				nbr_word_in_tab(char **tab);
char			**up_env(t_list *e);
void			trimtabarg(char **tabarg);
int				nbr_word_in_tab(char **tab);
void			case_path(char **tabarg, char **env);
void			fork_and_exe(char **tabarg, char **env, char *rightpath);
#endif
