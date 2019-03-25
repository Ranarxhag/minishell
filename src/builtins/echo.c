/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:26:52 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/25 18:26:54 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** add flag -n
*/

int		echo_builtin(char **instruction, t_env *env)
{
	int i;

	i = 1;
	while (instruction[i])
	{
		if (i > 1)
			ft_printf(" ");
		ft_printf("%s", instruction[i]);
		i++;
	}
	ft_printf("\n");
	if (env) {}
	return (1);
}
