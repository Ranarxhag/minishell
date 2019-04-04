/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:18:01 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/21 11:18:02 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&((*tab)[i]));
		i++;
	}
	ft_strdel((char**)tab);
}

void	error_message(char *message, char *var)
{
	ft_putstr_fd((char const *)message, 2);
	if (var != NULL)
		ft_putstr_fd((char const*)var, 2);
	ft_putchar_fd('\n', 2);
}
