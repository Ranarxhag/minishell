/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 07:21:58 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/09 07:21:59 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUILTINS (const char*[6]){"echo", "cd", "setenv", "unsetenv", "env", "exit"}

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"

/* A SUPPRIMER STDIO ? */
#include  <stdio.h>

typedef struct 		s_env
{
	char			*key;
	char			*value;
	struct s_env 	*next;
}					t_env;

void				set_environment(t_env **env, char **envp);
void				delete_environment(t_env **env);

int					execute_instructions(char **instructions, t_env *env);
int					execute_instruction(char **instruction, t_env *env);
int					execute_builtin(char **instruction, t_env *env);

int					is_builtin(char *command);

t_env				*new_env_item(char *key, char *value);
void				add_env_item_last(t_env **env, t_env *item);
void				add_env_item_first(t_env **env, t_env *item);
int					count_env_items(t_env *env);
void				delete_tab(char ***tab);

t_env				*find_env_item_by_value(t_env *env, char *value);
t_env				*find_env_item_by_key(t_env *env, char *key);

char				*set_path(char *command, t_env *env);

#endif