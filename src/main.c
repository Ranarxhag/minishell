/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 07:35:07 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/09 07:35:08 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_command(char *buff)
{
	char **instructions;

	if (!(instructions = ft_strsplit(buff, ';')))
		return (NULL);
	return (instructions);
}

int		is_valid_buff(char *buff)
{
	int i;

	i = 0;
	while (buff[i] && ft_isspace(buff[i]))
		i++;
	if (buff[i] == '\0')
		return (0);
	return (1);
}

char	*get_cwd(t_env *env)
{
	char	cwd[PATH_MAX];
	char	**tab;
	char	*name;
	t_env	*home;

	home = find_env_item_by_key(env, "HOME");
	if (!(getcwd(cwd, PATH_MAX)))
		return (NULL);
	if (home != NULL && ft_strequ(home->value, cwd))
		return (ft_strdup("~"));
	if (ft_strequ("/", cwd))
		return (ft_strdup(cwd));
	if (!(tab = ft_strsplit(cwd, '/')))
		return (NULL);
	if (!(name = ft_strdup(tab[ft_array_length((void**)tab) - 1])))
	{
		delete_tab(&tab);
		return (NULL);
	}
	delete_tab(&tab);
	return (name);
}

int		prompt_manager(t_env *env, char **buff)
{
	char	*gcw;

	if (!(gcw = get_cwd(env)))
		return (0);
	ft_printf("{bold}{yellow}↬ %s{eoc}{eocbold} ", gcw);
	ft_strdel(&gcw);
	if (get_next_line(0, buff) == -1)
		return (0);
	if (!is_valid_buff(*buff))
	{
		ft_strdel(buff);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*buff;
	char	**instructions;

	set_environment(&env, envp, argc, argv);
	instructions = NULL;
	while (1)
	{
		if (!prompt_manager(env, &buff))
			continue ;
		if (!(instructions = split_command(buff)))
			exit(EXIT_FAILURE);
		ft_strdel(&buff);
		if (!(execute_instructions(instructions, env)))
		{
			delete_tab(&instructions);
			delete_environment(&env);
			return (0);
		}
		delete_tab(&instructions);
	}
	return (0);
}
