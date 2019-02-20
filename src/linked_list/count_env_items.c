/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_env_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:42:26 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 14:42:27 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_env_items(t_env *env)
{
	t_env	*tmp;
	int		length;

	length = 0;
	tmp = env;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}
