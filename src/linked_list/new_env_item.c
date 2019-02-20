/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:39:07 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 14:39:15 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env_item(char *key, char *value)
{
	t_env *item;

	if (!(item = malloc(sizeof(*item))))
		return (NULL);
	if (!(item->key = ft_strdup((const char *)key)))
	{
		ft_memdel((void**)&(item));
		return (NULL);
	}
	if (!(item->value = ft_strdup((const char*)value)))
	{
		ft_strdel(&(item->key));
		ft_memdel((void**)&(item));
		return (NULL);
	}
	item->next = NULL;
	return (item);
}
