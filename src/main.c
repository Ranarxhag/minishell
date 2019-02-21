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
#include  <signal.h>


/*
int		main(void)
{
	pid_t	pid;
	char	buff[4096];
	char	**argv;
	while (1)
	{
		ft_printf("$> ");
		if (read(0, buff, 4096))
		{
			pid = fork();
			if (pid == 0)
			{
				argv = ft_strsplit(ft_strdupwc(buff, '\n'), ' ');
				if(execve(ft_strjoin("/bin/", argv[0]), argv, NULL) == -1)
					ft_printf("%s: command not found\n", argv[0]);
				ft_strdel(argv);
			}
			else
			{
				wait(NULL);
				continue ;
			}
		}
	}

	return 0;
}
*/

/*
int		execute_command(char *command)
{
	pid_t	pid;
	char	**args;

	if(!(args = ft_strsplit(command, ' ')))
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		printf("%s\n", ft_strjoin("~/Desktop/ft_ls/", args[0]));
		if (execve(ft_strjoin("~/Desktop/ft_ls/", args[0]), args, NULL) == -1)
			printf("Commande inconnue\n");
	}
	else
	{
		wait(NULL);
	}
	return (1);
}

char	*get_command(void)
{
	char	*buff;

	get_next_line(0, &buff);
	return (buff);
}
*/

char	**split_command(char *buff)
{
	char **instructions;

	if (!(instructions = ft_strsplit(buff, ';')))
		return (NULL);
	return (instructions);
}

void	delete_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&((*tab)[i]));
		i++;
	}
	ft_strdel(*tab);
	tab = NULL;
}

void	handle_signal(int signum)
{
	if (signum == SIGINT)
		exit(EXIT_FAILURE);
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

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*buff;
	char	**instructions;

	if (argv)
		argc = 1;
	set_environment(&env, envp);
	signal(SIGINT, handle_signal);
	instructions = NULL;
	while (1)
	{
		ft_printf("$> ");
		if (get_next_line(0, &buff) == -1 || !is_valid_buff(buff))
			continue ;
		if (!(instructions = split_command(buff)))
		{
			ft_strdel(&buff);
			delete_environment(&env);
		}
		ft_strdel(&buff);
		execute_instructions(instructions, env);
		delete_tab(&instructions);
	}
	return (0);
}

/*
int		main(int argc, char **argv, char **envp)
{
	char	*command;
	int i = 0;

	if (argv)
		argc = 1;
	while(envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}

	while (1)
	{
		ft_printf("$> ");
		if ((command = get_command()))
		{
			execute_command(command);
		}
	}
}
*/