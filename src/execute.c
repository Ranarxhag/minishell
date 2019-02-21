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

int	parse_items(char ***instruction)
{
	int i;
	char *tmp;

	i = 0;
	while ((*instruction)[i])
	{
		if (!(tmp = ft_strdupwc((*instruction)[i], '\t')))
			return (0);
		ft_strdel(&(*instruction)[i]);
		(*instruction)[i] = tmp;
	 	if (!(tmp = ft_strdupwc((*instruction)[i], '\v')))
			return (0);
		ft_strdel(&(*instruction)[i]);
		(*instruction)[i] = tmp;
		if (!(tmp = ft_strdupwc((*instruction)[i], '\n')))
			return (0);
		ft_strdel(&(*instruction)[i]);
		(*instruction)[i] = tmp;
		if (!(tmp = ft_strdupwc((*instruction)[i], '\r')))
			return (0);
		ft_strdel(&(*instruction)[i]);
		(*instruction)[i] = tmp;
		i++;
	}
	return (1);
}

int		execute_instruction(char **instruction, t_env *env)
{
	char	*path;
	pid_t	pid;
	char	**enstr;

	if (!(parse_items(&instruction)))
		return (0);
	if (is_builtin(instruction[0]))
		return (execute_builtin(instruction, env));
	if (!(path = set_path(instruction, env)))
		return (0);
	enstr = env_to_string(env);
	pid = fork();
	if (pid == 0)
		execve(path, instruction, enstr);
	wait(NULL);
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
		handle_expansions(&(instructions[i]), env);
		if (!(parts = ft_strsplit(instructions[i], ' ')))
		{
			i++;
			continue ;
		}
		execute_instruction(parts, env);
		delete_tab(&parts);
		i++;
	}
	return (1);
}
