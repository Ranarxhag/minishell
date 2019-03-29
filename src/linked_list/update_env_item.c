/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:21:06 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/29 10:21:07 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_item(t_env **env, char *key, char *value)
{
	t_env *item;

	if (env == NULL || key == NULL)
		return ;
	if (!(item = find_env_item_by_key(*env, key)))
	{
		add_env_item_last(env, new_env_item(key, value));
		return ;
	}
	ft_strdel(&(item->value));
	item->value = (value == NULL) ? ft_strdup("") : ft_strdup(value);
}
