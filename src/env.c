/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:59 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 14:12:00 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_string_env(char ***str, int i)
{
	while (i >= 0)
	{
		ft_strdel(str[i]);
		i--;
	}
	*str = NULL;
	str = NULL;
}

char	**env_to_string(t_env *env)
{
	char	**str;
	int		length;
	int		i;
	t_env	*tmp;

	i = 0;
	length = count_env_items(env);
	if (!(str = (char**)malloc(sizeof(char*) * (length + 1))))
		return (NULL);
	str[length] = NULL;
	tmp = env;
	while (i < length)
	{
		if (!(str[i] = ft_str3join(tmp->key, "=", tmp->value)))
		{
			del_string_env(&str, --i);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	return (str);
}

void	delete_environment(t_env **env)
{
	t_env *next;

	next = NULL;
	while (*env)
	{
		next = (*env)->next;
		ft_strdel(&((*env)->key));
		ft_strdel(&((*env)->value));
		ft_memdel((void**)&(*env));
		*env = next;
	}
	exit(EXIT_FAILURE);
}

/*
** 'argc' and 'argv' parameters are just there because of -Wall -Wextra -Werror
** flags
*/

void	set_environment(t_env **env, char **envp, int argc, char **argv)
{
	int		i;
	t_env	*node;
	char	**tab;

	argc = 0;
	argv = NULL;
	i = 0;
	*env = NULL;
	node = NULL;
	tab = NULL;
	while (envp[i])
	{
		if (!(tab = ft_strsplit(envp[i], '=')) ||
			ft_array_length((void**)tab) != 2)
		{
			delete_tab(&tab);
			delete_environment(env);
		}
		if (!(node = new_env_item(tab[0], tab[1])))
		{
			delete_tab(&tab);
			delete_environment(env);
		}
		add_env_item_last(env, node);
		delete_tab(&tab);
		i++;
	}
}
