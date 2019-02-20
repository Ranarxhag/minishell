/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:24:57 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 17:24:58 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		execute_instruction(char **instruction, t_env *env)
{
	char	*path;

	if (is_builtin(instruction[0]))
		return (execute_builtin(instruction, env));
	if (!(path = set_path(instruction[0], env)))
		return (0);
	return (1);
}

int		execute_instructions(char **instructions, t_env *env)
{
	int 	i;
	char	**parts;

	i = 0;
	parts = NULL;
	while (instructions[i])
	{
		if (!(parts = ft_strsplit(instructions[i], ' ')))
		{
			i++;
			continue ;
		}
		execute_instruction(parts, env);
		i++;
	}
	return (1);
}
