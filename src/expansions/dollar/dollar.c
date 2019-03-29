/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:51:13 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/21 16:51:14 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				del_part1(char **part1)
{
	ft_strdel(part1);
	return (0);
}

char			*replace_variable(char *str, t_env *env)
{
	int		length;
	char	*variable;
	char	*part2;

	length = 0;
	while (ft_isupper(str[length]) || ft_islower(str[length]) ||
		ft_isdigit(str[length]) || str[length] == '_')
		length++;
	if (!(variable = ft_strsub(str, 0, length)))
		return (NULL);
	if (find_env_item_by_key(env, variable) == NULL)
	{
		ft_printf("%s: Undefined variable\n", variable);
		ft_strdel(&variable);
		return (NULL);
	}
	part2 = ft_strjoin((find_env_item_by_key(env, variable))->value,
		&(str[length]));
	ft_strdel(&variable);
	return (part2);
}

int				dollar_expansion(char **command, t_env *env)
{
	char	*part1;
	char	*part2;
	char	*tmp;

	tmp = NULL;
	while ((part2 = ft_strchr(*command, '$')))
	{
		if (!(part1 = ft_strsub(*command, 0, ft_strlen(*command) -
			ft_strlen(part2))))
			return (0);
		part2++;
		if (!(part2 = replace_variable(part2, env)))
			return (del_part1(&part1));
		if ((tmp = ft_strjoin(part1, part2)))
		{
			free(*command);
			*command = tmp;
		}
		ft_strdel(&part1);
		ft_strdel(&part2);
	}
	return (1);
}
