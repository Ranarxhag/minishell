/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 07:21:58 by bjovanov          #+#    #+#             */
/*   Updated: 2019/03/29 14:31:52 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUILTINS (const char*[6]){"echo","cd","setenv","unsetenv","env"}

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

void				set_environment(t_env **env, char **envp, int argc,
					char **argv);
void				delete_environment(t_env **env);
char				**env_to_string(t_env *env);

int					execute_instructions(char **instructions, t_env *env);
int					execute_instruction(char **instruction, t_env *env);
int					execute_builtin(char **instruction, t_env *env);

int					is_builtin(char *command);

t_env				*new_env_item(char *key, char *value);
void				add_env_item_last(t_env **env, t_env *item);
void				add_env_item_first(t_env **env, t_env *item);
void				update_env_item(t_env **env, char *key, char *value);
int					count_env_items(t_env *env);
void				delete_tab(char ***tab);

t_env				*find_env_item_by_value(t_env *env, char *value);
t_env				*find_env_item_by_key(t_env *env, char *key);

t_env				*delete_env_item_by_key(t_env **env, char *key);
t_env				*delete_env_item_first(t_env **env);

char				*set_path(char **command, t_env *env);

void				error_message(char *message, char *var);

int					handle_expansions(char **command, t_env *env);
int					tilde_expansion(char **command);
int					dollar_expansion(char **command, t_env *env);

char				**parse_cmd(char *cmd);

int					cd_builtin(char	**instruction, t_env *env);
int					echo_builtin(char **instruction);
int					env_builtin(char **instruction, t_env *env);
int					exit_builtin(char **instruction, t_env *env);
int					setenv_builtin(char **instruction, t_env *env);
int					unsetenv_builtin(char **instruction, t_env *env);
#endif
