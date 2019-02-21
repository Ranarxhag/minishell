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

char	*replace_tilde(char *part2, t_env *env)
{
	part2++;
	if (part2[0] == '+')
		return (ft_strjoin((find_env_item_by_key(env, "PWD"))->value,
			&(part2[1])));
	else if (part2[0] == '-')
		return (ft_strjoin((find_env_item_by_key(env, "OLDPWD"))->value,
			&(part2[1])));
	else if (ft_islower(part2[0]) || ft_isupper(part2[0]))
		return (ft_strjoin("/Users/", part2));
	return (ft_strjoin((find_env_item_by_key(env, "HOME"))->value, part2));
}

int		tilde_expansion(char **command, t_env *env)
{
	char *part1;
	char *part2;
	char *tmp;

	tmp = NULL;
	while ((part2 = ft_strchr(*command, '~')))
	{
		if (!(part1 = ft_strsub(*command, 0, ft_strlen(*command) -
			ft_strlen(part2))))
			return (0);
		if (!(part2 = replace_tilde(part2, env)))
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
