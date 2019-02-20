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

void	set_environment(t_env **env, char **envp)
{
	int i;
	t_env *node;
	char	**tab;

	i = 0;
	*env = NULL;
	node = NULL;
	tab = NULL;
	while (envp[i])
	{
		if (!(tab = ft_strsplit(envp[i], '=')) ||
			ft_array_length((void**)tab) != 2)
			delete_environment(env);
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
