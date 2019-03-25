/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:27:10 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/25 18:27:11 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		unsetenv_builtin(char **instruction, t_env *env)
{
	ft_printf("%s called !\n", instruction[0]);
	if (env) {}
	return (1);
}
