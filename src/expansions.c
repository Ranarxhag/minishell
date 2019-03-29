/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:49:59 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/21 14:50:00 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		handle_expansions(char **command, t_env *env)
{
	if (ft_strchr(*command, '~'))
		if (!(tilde_expansion(command)))
			return (0);
	if (ft_strchr(*command, '$'))
		if (!(dollar_expansion(command, env)))
			return (0);
	return (1);
}
