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

int		is_valid_params(char **instruction)
{
	int i;

	i = 0;
	if (ft_array_length((void**)instruction) > 3)
	{
		ft_printf("setenv: too many arguments\n");
		return (0);
	}
	if (!ft_isalpha(instruction[1][0]))
	{
		ft_printf("setenv: Variable must begin with a letter\n");
		return (0);
	}
	while (instruction[1][i])
	{
		if (!ft_isalnum(instruction[1][i]))
		{
			ft_printf("setenv: Variable name must contains alphanumerics"
				" characters\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int		setenv_builtin(char **instruction, t_env *env)
{
	t_env *item;

	if (ft_array_length((void**)instruction) == 1)
		return (env_builtin(instruction, env));
	if (!is_valid_params(instruction))
		return (0);
	if (!(item = find_env_item_by_key(env, instruction[1])))
	{
		add_env_item_last(&env, new_env_item(instruction[1],
			instruction[2] ? instruction[2] : ""));
	}
	else
	{
		ft_strdel(&(item->value));
		item->value = instruction[2] ? ft_strdup(instruction[2]) :
			ft_strdup("");
	}
	return (1);
}
