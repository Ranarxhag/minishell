/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:55:58 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/25 17:55:59 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		handle_path_error(struct stat *dest, char *path)
{
	if (lstat(path, dest) == -1)
	{
		ft_printf("%s: No such file or directory\n", path);
		return (0);
	}
	if (!S_ISDIR(dest->st_mode))
	{
		ft_printf("%s: Not a directory\n", path);
		return (0);
	}
	if (!(dest->st_mode & S_IXUSR))
	{
		ft_printf("%s: Permission denied\n", path);
		return (0);
	}
	return (1);
}

int		change_dir(char *path, t_env *env, char **prev)
{
	struct stat dest;
	char		cwd[PATH_MAX];

	if (!handle_path_error(&dest, path))
		return (0);
	if (!(getcwd(cwd, PATH_MAX)))
		return (0);
	if (chdir(path) == 0)
	{
		update_env_item(&env, "OLDPWD", cwd);
		ft_strdel(prev);
		if (!(*prev = ft_strdup(cwd)))
			return (0);
		getcwd(cwd, PATH_MAX);
		update_env_item(&env, "PWD", cwd);
		return (1);
	}
	return (0);
}

int		cd_no_params(t_env *home, t_env *env, char **prev)
{
	if (!home)
	{
		ft_printf("cd: No home directory\n");
		return (0);
	}
	if (!(change_dir(home->value, env, prev)))
		return (0);
	return (1);
}

int		cd_builtin(char **instruction, t_env *env)
{
	static char	*prev = NULL;
	int			nb_params;

	nb_params = ft_array_length((void**)instruction);
	if (nb_params > 2)
	{
		ft_printf("cd: Too many arguments\n");
		return (0);
	}
	if (nb_params == 1 || (nb_params == 2 && ft_strequ(instruction[1], "--")))
		return (cd_no_params(find_env_item_by_key(env, "HOME"), env, &prev));
	if (ft_strequ(instruction[1], "-"))
		return (change_dir(prev, env, &prev));
	else
	{
		if (!(change_dir(instruction[1], env, &prev)))
			return (0);
	}
	return (1);
}
