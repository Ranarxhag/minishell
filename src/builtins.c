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
	printf("%s est un builtin\n", instruction[0]);
	if (env) {}
	return (1);
}
