/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:33:35 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/28 12:33:36 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*delete_env_item_first(t_env **env)
{
	ft_strdel(&((*env)->key));
	ft_strdel(&((*env)->value));
	if (count_env_items(*env) == 1)
	{
		free(*env);
		*env = NULL;
		return (*env);
	}
	(*env)->key = (*env)->next->key;
	(*env)->value = (*env)->next->value;
	(*env)->next = (*env)->next->next;
	free((*env)->next);
	return (*env);
}

t_env	*delete_env_item_by_key(t_env **env, char *key)
{
	t_env	*prev;
	t_env	*searched;
	int		i;

	prev = *env;
	searched = (*env)->next;
	i = 0;
	if (ft_strequ(prev->key, key))
		return (delete_env_item_first(env));
	while (searched)
	{
		if (ft_strequ(searched->key, key))
			break ;
		if (i++ > 0)
			prev = searched;
		searched = searched->next;
	}
	if (searched == NULL)
		return (NULL);
	prev->next = searched->next;
	ft_strdel(&(searched->key));
	ft_strdel(&(searched->value));
	free(searched);
	searched = NULL;
	return (*env);
}
