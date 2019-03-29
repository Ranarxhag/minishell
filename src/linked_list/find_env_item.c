/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:59:58 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 18:00:01 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*find_env_item_by_key(t_env *env, char *key)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strequ(tmp->key, key))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

t_env	*find_env_item_by_value(t_env *env, char *value)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strequ(tmp->value, value))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
