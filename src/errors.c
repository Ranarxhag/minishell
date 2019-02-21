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

void	error_message(char *message, char *var)
{
	ft_putstr_fd((char const *)message, 2);
	ft_putstr_fd((char const*)var, 2);
	ft_putchar_fd('\n', 2);
}