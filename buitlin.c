/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 03:55:42 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/09 07:39:04 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_env(t_list *env)
{
	while (env)
	{
		ft_putendl(env->content);
		env = env->next;
	}
}

static char		*getvar(const char *str)
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

void	ft_cd(char *path)
{
	chdir(path);
	//ft_setenv("PWD",
}
void	ft_unsetenv(t_list **env, char *var)
{
	t_list *ltmp;
	char	*ctmp;

	ctmp = getvar((*env)->content);
	if (!strcmp(ctmp, var))
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
		if (!strcmp(ctmp, var))
		{
			ltmp->next = (*env)->next;
			freelist(*env);
		}
		ltmp = (*env);
		*env = (*env)->next;
	}
}

void	ft_setenv(t_list *env, char *var, char *content)
{
	char *tmpvar;
	char *new_var_env;
	t_list *tmp;

	new_var_env = ft_strjoin(var, "=");
	ft_strrealloc((char **)&(new_var_env), content);
	if (env == NULL)
	{
		env = ft_lstnew(new_var_env, ft_strlen(new_var_env) + 1);
		free(new_var_env);
		return;
	}
	while (env)
	{
		tmpvar = getvar(env->content);
		if (!ft_strcmp(tmpvar, var))
		{
			free(tmpvar);
			free(env->content);
			env->content = new_var_env;
			return ;
		}
		free(tmpvar);
		tmp = env;
		env = env->next;
	}
	tmp->next = ft_lstnew(new_var_env, ft_strlen(new_var_env) + 1);
}

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
