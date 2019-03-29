/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:44:32 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 17:44:34 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		(*get_builtin_func(char *name))(char**, t_env*)
{
	if (ft_strequ("cd", name))
		return (&cd_builtin);
	else if (ft_strequ("setenv", name))
		return (&setenv_builtin);
	else if (ft_strequ("env", name))
		return (&env_builtin);
	else if (ft_strequ("unsetenv", name))
		return (&unsetenv_builtin);
	return (0);
}

int		is_builtin(char *command)
{
	int i;

	i = 0;
	while (BUILTINS[i])
	{
		if (ft_strequ(BUILTINS[i], command))
			return (1);
		i++;
	}
	return (0);
}

int		execute_builtin(char **instruction, t_env *env)
{
	if (ft_strequ("echo", instruction[0]))
	{
		if (!(echo_builtin(instruction)))
			return (0);
	}
	else
	{
		if (!(get_builtin_func(instruction[0])(instruction, env)))
			return (0);
	}
	return (1);
}
