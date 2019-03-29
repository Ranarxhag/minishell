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
	int i;

	if (ft_array_length((void**)instruction) == 1)
	{
		ft_printf("setenv: too few arguments\n");
		return (0);
	}
	i = 1;
	while (instruction[i])
	{
		if (find_env_item_by_key(env, instruction[i]))
			env = delete_env_item_by_key(&env, instruction[i]);
		i++;
	}
	return (1);
}
