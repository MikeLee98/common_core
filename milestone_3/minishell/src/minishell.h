/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:59:57 by mario             #+#    #+#             */
/*   Updated: 2025/11/24 15:41:46 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "../libft/libft.h"
#include <stdlib.h>

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;

//env
t_env   *init_env(char **envp);
void    env_add_back(t_env **env, t_env *new);
t_env   *env_new(char *str);
char    *extract_value(char *str);
char    *extract_key(char *str);
void    env_set(t_env **env, char *key, char *value);
void    env_unset(t_env **env, char *key);
char    *env_get_value(t_env *env, char *key);
t_env   *env_find(t_env *env, char *key);
char    **env_to_array(t_env *env);
int 	env_update(t_env *env, char *key, char *new_value);

//built_ins
void	ft_env(t_env *env);

#endif
