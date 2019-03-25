/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:26:58 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/25 18:26:59 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		env_builtin(char **instruction, t_env *env)
{
	ft_printf("%s called !\n", instruction[0]);
	if (env) {}
	return (1);
}
