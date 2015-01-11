/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 03:55:42 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 10:48:06 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*void	ft_env(t_list **env, char **tabarg)
{
	t_list *tmp;
	tmp = *env;
	if (tabarg[0][0] == 'e')
	{
		while (tmp)
		{
			ft_putendl((tmp)->content);
			tmp = tmp->next;
		}
	}
}*/

char		*getvar(const char *str)
{
	int i;
	char *ret;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	ret = ft_strndup(str, i);
	return (ret);
}

void	freelist(t_list *env)
{
	free(env->content);
	free(env->next);
	free(env);
}

/*void	ft_cd(t_list **env, char **tabarg)
{
	chdir(tabarg[1]);
	//ft_setenv("PWD",
}

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
}*/

/*
int main(int argc, char **argv, char **env)
{
//	ft_putendl(getvar("asd"));
	t_list *e;
	e = tabtolist(env);
	ft_setenv(e,"PATH", "salut");

	ft_env(e);

	return (0);
}*/
