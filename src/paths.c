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
		return (0);
	if (lstat(path, file) == -1)
	{
		ft_memdel((void**)&(file));
		return (-1);
	}
	if (!(file->st_mode & S_IXUSR))
	{
		ft_memdel((void**)&(file));
		return (-2);
	}
	ft_memdel((void**)&(file));
	return (1);
}

char	*set_origin_path(char *command)
{
	int		res;
	char	*path;
	char	*value;
	char	cwd[PATH_MAX];

	if (!(getcwd(cwd, PATH_MAX)))
		return (NULL);
	value = command[0] == '/' ? "" : cwd;
	if (!(path = ft_str3join(value, value[ft_strlen(
		value) - 1] == '/' ? "" : "/", command)))
		return (NULL);
	if ((res = try_path(path)) == -1)
		error_message("minishell: no such file or directory: ", command);
	else if (res == -2)
		error_message("minishell: permission denied: ", command);
	if (res <= 0)
	{
		ft_strdel(&path);
		return (NULL);
	}
	return (path);
}

char	**get_env_path(char *command, t_env *env, int *res, int *i)
{
	t_env *path;

	*i = -1;
	*res = 0;
	path = find_env_item_by_key(env, "PATH");
	if (!path)
	{
		ft_printf("%s: No such file or directory\n", command);
		return (NULL);
	}
	return (ft_strsplit(path->value, ':'));
}

char	*set_env_path(char *command, t_env *env)
{
	char	**env_paths;
	char	*tmp;
	int		res;
	int		i;

	if (!(env_paths = get_env_path(command, env, &res, &i)))
		return (NULL);
	tmp = NULL;
	while (env_paths[++i])
	{
		if (!(tmp = ft_str3join(env_paths[i], env_paths[i][ft_strlen(
			env_paths[i]) - 1] == '/' ? "" : "/", command)))
			return (NULL);
		if ((res = try_path(tmp)) <= 0)
			ft_strdel(&tmp);
		else
		{
			delete_tab(&env_paths);
			return (tmp);
		}
	}
	error_message("minishell: command not found: ", command);
	delete_tab(&env_paths);
	return (NULL);
}

char	*set_path(char **command, t_env *env)
{
	char	*path;

	path = NULL;
	if (ft_strchr(*command, '/'))
	{
		if (!(path = set_origin_path(*command)))
			return (NULL);
	}
	else
	{
		if (!(path = set_env_path(*command, env)))
		{
			ft_strdel(&path);
			return (NULL);
		}
	}
	ft_strdel(&(command[0]));
	command[0] = ft_strdup(path);
	return (path);
}
