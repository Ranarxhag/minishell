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

static char		**delete_cmd_tab(char **tab, int j)
{
	while (j >= 0)
	{
		ft_strdel(&(tab[j]));
		j--;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static int		get_word_length(char *cmd, int *quote)
{
	int count;

	count = 0;
	if (cmd[0] == '"' || cmd[0] == '\'')
	{
		*quote = 1;
		return ((int)ft_strclen((const char*)cmd + 1,
			cmd[0] == '"' ? '"' : '\''));
	}
	while (cmd[count] && !ft_isspace(cmd[count]))
		count++;
	return (count);
}

static int		count_words(char *cmd)
{
	int i;
	int words;
	int quote;
	int length;

	i = 0;
	words = 0;
	quote = 0;
	length = 0;
	while (cmd[i])
	{
		if (!ft_isspace(cmd[i]))
		{
			words++;
			length = get_word_length(&(cmd[i]), &quote);
			i += length + (quote == 1 ? 3 : 0);
			quote = 0;
		}
		i++;
	}
	return (words);
}

static int		create_words(char *cmd, char **tab, size_t i, unsigned int *j)
{
	int length;
	int quote;

	length = 0;
	quote = 0;
	while (cmd[i])
	{
		if (!ft_isspace(cmd[i]))
		{
			length = get_word_length(&(cmd[i]), &quote);
			if (!(tab[*j] = ft_strsub((const char*)cmd, i + quote, length)))
				return (0);
			(*j)++;
			i += length + ((quote == 1) ? 2 : 0);
			quote = 0;
		}
		else
			i++;
	}
	tab[*j] = NULL;
	return (1);
}

char			**parse_cmd(char *cmd)
{
	char			**tab;
	unsigned int	j;

	if (cmd == NULL)
		return (NULL);
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(cmd) + 1))))
		return (NULL);
	if (!(create_words(cmd, tab, 0, &j)))
		return (delete_cmd_tab(tab, j - 1));
	return (tab);
}
