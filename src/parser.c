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
	int words;

	i = -1;
	words = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '"')
		{
			i += ft_strlen(cmd) - ft_strclen(&(cmd[i + 1]), '"') - i;
			continue ;
		}
		if ((i == 0 && !ft_isspace(cmd[i])) || (ft_isspace(cmd[i]) &&
			(!ft_isspace(cmd[i + 1]) && cmd[i + 1] != '\0')))
			words++;
	}
	return (1);
}

int		create_words(char *cmd, char **tab, size_t i, int j)
{
	unsigned int	start;
	size_t			length;
	int			apo;

	start = 0;
	length = 0;
	apo = 0;
	while (cmd[i])
	{
		length = 0;
		if ((i == 0 && !ft_isspace(cmd[i])) || (ft_isspace(cmd[i]) &&
			(!ft_isspace(cmd[i + 1]) && cmd[i + 1] != '\0')))
		{
			start = (cmd[i + ((i == 0) ? 0 : 1)] == '"') ? 1 : 0;
			if (cmd[i + ((i == 0) ? 0 : 1)] == '"')
			{
				length = ft_strclen(&(cmd[i + ((i == 0) ? 1 : 2)]), '"');
				apo = 1;
			}
			while (!ft_isspace(cmd[i + length + ((i == 0) ? 0 : 1)]))
				length++;
			if (!(tab[++j] = ft_strsub(&(cmd[i + ((i == 0) ? 0 : 1)]), start, length + ((i == 0) ? 0 : 0))))
				return (0);
			if (apo)
			{
				i += ft_strclen(&(cmd[i + ((i == 0) ? 1 : 2)]), '"');
				continue ;
			}
		}
		i++;
	}
	tab[++j] = NULL;
	return (1);
}

char	**parse_cmd(char *cmd)
{
	char	**tab;
	char	*tmp;

	if (cmd == NULL)
		return (NULL);
	if (!(tmp = ft_strdupwstr(cmd, "\"\"")))
		return (NULL);
	ft_strdel(&cmd);
	cmd = tmp;
	if(!(tab = (char**)malloc(sizeof(char*) * (count_words(cmd) + 1))))
		return (NULL);
	if (!(create_words(cmd, tab, 0, -1)))
	{

	}
	return (tab);
}

int		main()
{
	char **tab;
	int i;

	//tab = parse_cmd(ft_strdup("      echo coucou les  gens \"coucou      les       gens\"\"coucou\"abcdef       "));
	tab = parse_cmd(ft_strdup("echo \"Bonjour\""));
	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
