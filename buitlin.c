/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 03:55:42 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/08 04:51:44 by hhismans         ###   ########.fr       */
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

char	*getvar(const char *str)
{
	int i;
	char *ret;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	ret = ft_strndup(str, i);
	return (ret);
}

void	ft_setenv(t_list *env, char *var, char *content)
{
	char *tmpvar;
	char new_var_env;

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
		if (ft_strcmp(tmpvar, var))
		{
			free(tmpvar);
			free(env->content);
			env->content = new_var_env;
			return ;
		}
		free(tmpvar);
		if ((env = env->next) || !env->next)
			break;
	}
	env->next = ft_lstnew(new_var_env, ft_strlen(tmpvar) + 1);
}


int main(int argc, char **argv, char **env)
{
//	ft_putendl(getvar("asd"));
	t_list *e;


	return (0);
}
