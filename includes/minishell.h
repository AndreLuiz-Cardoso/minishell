/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <luis-fif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:51:15 by luis-fif          #+#    #+#             */
/*   Updated: 2024/10/16 10:39:27 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H



# include "libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdbool.h>


# define INTER_COMMANDS 7


typedef struct s_token  t_token;

struct  s_token
{
	bool	double_quotes;
	char	*token;
	t_token	*prev;
	t_token	*next;
};

//list_create
t_token *create_tkn_lst(t_token *token);

void	test_print(char *token);

// int g_signal = 0;s

/*print.c*/
void ft_print(char *message);
/*ft_print_ascii.c*/
void print_header(void);
//void print_ascii(void);

/*utils_1.c*/
int		ft_strcmp(const char *s1, const char *s2);
char *ft_strncpy(char *dest, const char *src, size_t n);
int count_words(const char *str);
char **ft_strtok(char *str);
void free_tokens(char **tokens);
int prompt(void);

/*signal.c*/
// void	signal_handler(int sig);

/*cm_built_in_utils_1.c*/
int ft_strcomp(const char *ident, const char *to_find);
char *ch_int_commands(char *str);

/*cm_built_in.c*/
int	is_builtin_cmd(char **tokens);
int builtin_pwd(char **tokens);
void builtin_cd(char **tokens);
void	builtin_exit(char *status);
void	builtin_ls(void);

int ft_prev_dir(char *tokens);
int ft_echo(char **args);

#endif