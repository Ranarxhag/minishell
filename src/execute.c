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
	pid_t	pid;
	char	**enstr;

	if (is_builtin(instruction[0]))
		return (execute_builtin(instruction, env));
	if (!(path = set_path(instruction, env)))
		return (0);
	if (!(enstr = env_to_string(env)))
	{
		ft_strdel(&path);
		return (0);
	}
	pid = fork();
	if (pid == 0)
		execve(path, instruction, enstr);
	wait(NULL);
	return (1);
}

/*
** For execute_instruction() function, not need to protect it because we want
** to free 'parts' in all cases and we don't want to stop the execution
*/
int		execute_instructions(char **instructions, t_env *env)
{
	int 	i;
	char	**parts;

	i = 0;
	parts = NULL;
	while (instructions[i])
	{
		handle_expansions(&(instructions[i]), env);
		if (!(parts = parse_cmd(instructions[i])))
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
