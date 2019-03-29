/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:52:55 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/21 14:52:55 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*replace_tilde(char *part2)
{
	part2++;
	if (!ft_isspace(part2[0]) && part2[0] != '\0')
		return (ft_strjoin("/Users/", part2));
	return (ft_strdup("$HOME"));
}

static int		in_single_quote(char *command, char *part2)
{
	int squote;
	int i;

	i = 0;
	squote = 0;
	while (!ft_strnequ(&(command[i]), part2, ft_strlen(part2)))
	{
		if (command[i] == '\'' || command[i] == '"')
			squote = (squote == 1) ? 0 : 1;
		i++;
	}
	return (squote);
}

int				tilde_expansion(char **command)
{
	char *part1;
	char *part2;
	char *tmp;

	tmp = NULL;
	while ((part2 = ft_strchr(*command, '~')) &&
		!in_single_quote(*command, part2))
	{
		if (!(part1 = ft_strsub(*command, 0, ft_strlen(*command) -
			ft_strlen(part2))))
			return (0);
		if (!(part2 = replace_tilde(part2)))
		{
			ft_strdel(&part1);
			return (0);
		}
		if ((tmp = ft_strjoin(part1, part2)))
		{
			free(*command);
			*command = tmp;
		}
		ft_strdel(&part2);
		ft_strdel(&part1);
	}
	return (1);
}
