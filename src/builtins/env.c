/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:26:58 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/25 18:26:59 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	delete_tmpenv(t_env **tmpenv)
{
	t_env *next;

	next = NULL;
	while (*tmpenv)
	{
		next = (*tmpenv)->next;
		ft_strdel(&((*tmpenv)->key));
		ft_strdel(&((*tmpenv)->value));
		ft_memdel((void**)&(*tmpenv));
		*tmpenv = next;
	}
}

t_env	*set_tmpenv(t_env *env)
{
	t_env *tmpenv;
	t_env *tmp;

	tmp = env;
	tmpenv = NULL;
	while (tmp)
	{
		add_env_item_last(&tmpenv, new_env_item(tmp->key, tmp->value));
		tmp = tmp->next;
	}
	return (tmpenv);
}

/*
** Free directly 'key' if 'value' fail is not obliged because add_env_item_last
** and new_env_item functions will just return NULL and both variables will
** be deleted just after the end of the loop turn
*/

void	add_items_to_tmpenv(t_env *tmpenv, char **instruction)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	key = NULL;
	value = NULL;
	while (instruction[++i])
	{
		if (ft_strchr(instruction[i], '=') && instruction[i][0] != '=')
		{
			key = ft_strsub(instruction[i], 0, ft_strclen(instruction[i], '='));
			value = ft_strsub(instruction[i], ft_strclen(instruction[i], '=')
				+ 1, ft_strlen(instruction[i]) -
				ft_strclen(instruction[i], '='));
			update_env_item(&tmpenv, key, value);
			ft_strdel(&key);
			ft_strdel(&value);
		}
	}
}

int		env_builtin(char **instruction, t_env *env)
{
	t_env *tmpenv;
	t_env *tmp;

	tmpenv = set_tmpenv(env);
	tmp = tmpenv;
	if (ft_array_length((void**)instruction) > 1)
		add_items_to_tmpenv(tmpenv, instruction);
	while (tmp)
	{
		ft_printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	delete_tmpenv(&tmpenv);
	return (1);
}
