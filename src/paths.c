/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:12:12 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/20 18:12:12 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		try_path(char *path)
{	
	struct stat *file;

	if (!(file = malloc(sizeof(*file))))
		return (NULL);
	if (lstat(path, file) == -1)
	{
		ft_memdel((void**)&(file));
		ft_printf("minishell: no such file or directory: %s\n", path);
		return (0);
	}
	if (!(file->st_mode & S_IXUSR))
	{
		ft_memdel((void**)&(file));
		/* POUR CHAQUE PRINTF FAUT METTRE SUR SORTIE ERREUR */
		ft_printf("minishell: permission denied: %s\n", path);
	}
	return (1);
}

char	*set_env_path(char *command, t_env *env)
{
	char	*env_paths;
	char	*tmp;

	if (!(env_paths = ft_strsplit(
		(find_env_item_by_key(env, "PATH"))->value, ':')))
		return (NULL);
	while (*env_paths)
	{
		/* FAIRE UN str3join() ? Pour concatener le path + / + command */
		env_paths++;
	}
}

char	*set_path(char *command, t_env *env)
{
	char	*path;

	path = NULL;
	if (ft_strchr(command, '/'))
	{
		if (!(path = ft_strdup(command)))
			return (NULL);
		if (!try_path(path))
		{
			ft_strdel(&path);
			return (NULL);
		}
	}
	else
	{
		if (!(path = set_env_path(command, env)))
		{
			ft_strdel(&path);
			return (NULL);
		}
	}
	return (path);
}
