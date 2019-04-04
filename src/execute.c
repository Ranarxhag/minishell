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

static int	is_valid_instruction(char *instruction)
{
	int i;

	i = 0;
	while (ft_isspace(instruction[i]))
		i++;
	if (instruction[i] == '\0')
		return (0);
	if (ft_strequ(".", instruction) || ft_strequ("..", instruction))
		return (0);
	return (1);
}

int			execute_instruction(char **instruction, t_env *env)
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
	delete_tab(&enstr);
	ft_strdel(&path);
	return (1);
}

/*
** For execute_instruction() function, not need to protect it because we want
** to free 'parts' in all cases and we don't want to stop the execution
*/

int			execute_instructions(char **instructions, t_env *env)
{
	int		i;
	char	**parts;

	i = 0;
	parts = NULL;
	while (instructions[i])
	{
		if (!is_valid_instruction(instructions[i]) ||
			!handle_expansions(&(instructions[i]), env) ||
			!(parts = parse_cmd(instructions[i])))
		{
			i++;
			continue ;
		}
		if (ft_strequ(parts[0], "exit"))
		{
			delete_tab(&parts);
			return (0);
		}
		execute_instruction(parts, env);
		delete_tab(&parts);
		i++;
	}
	return (1);
}
