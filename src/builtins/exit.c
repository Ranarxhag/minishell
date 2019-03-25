/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:27:02 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/25 18:27:03 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		exit_builtin(char **instruction, t_env *env)
{
	ft_printf("%s called !\n", instruction[0]);
	if (env) {}
	return (1);
}
