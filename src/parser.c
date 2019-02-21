/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:40:51 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/21 19:40:52 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_words(char *cmd)
{
	int i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '"')
		{
			i += ft_strlen(cmd) - ft_strlen(ft_strchr(&(cmd[i + 1]), '"')) - i;
			continue ;
		}
		ft_printf("%s\n", &(cmd[i]));
	}
	ft_printf("\n");
	return (1);
}

char	**parse_cmd(char *cmd)
{
	char	**tab;

	if (cmd == NULL)
		return (NULL);
	if(!(tab = (char**)malloc(sizeof(char*) * (count_words(cmd) + 1))))
		return (NULL);
	tab[count_words(cmd)] = NULL;
	return (tab);
}

int		main()
{
	char **tab;
	int i;

	tab = parse_cmd("echo \"Coucou\" Je lol \"Salut\"");
	i = 0;
	/*
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
	*/
	return (0);
}
