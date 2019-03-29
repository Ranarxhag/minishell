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

int		nflag(char **instruction)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (instruction[i])
	{
		j = 1;
		if (instruction[i][0] != '-')
			return (i);
		while (instruction[i][j])
		{
			if (instruction[i][j] != 'n')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int		echo_builtin(char **instruction)
{
	int i;
	int iteration;
	int flag;

	iteration = 0;
	i = nflag(instruction);
	flag = (i > 1) ? 1 : 0;
	while (instruction[i])
	{
		if (iteration > 0)
			ft_printf(" ");
		ft_printf("%s", instruction[i]);
		i++;
		iteration++;
	}
	if (!flag)
		ft_printf("\n");
	return (1);
}
