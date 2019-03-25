/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:27:06 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/25 18:27:07 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		setenv_builtin(char **instruction, t_env *env)
{
	ft_printf("%s called !\n", instruction[0]);
	if (env) {}
	return (1);
}
