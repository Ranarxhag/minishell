/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:40:22 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 14:40:23 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_item_last(t_env **env, t_env *item)
{
	if (env == NULL || item == NULL)
		return ;
	if (*env == NULL)
	{
		*env = item;
		return ;
	}
	if ((*env)->next)
		add_env_item_last(&((*env)->next), item);
	if (!(*env)->next)
		(*env)->next = item;
}

void	add_env_item_first(t_env **env, t_env *item)
{
	if (env == NULL || item == NULL)
		return ;
	item->next = *env;
	*env = item;
}