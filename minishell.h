/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:09:23 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/01/11 14:23:13 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_precedence
{
	char		precedence[11];
}				t_precedence;

typedef struct s_command
{
	int			order_precedence;
	int			order_sentence;
	char		*cmd;
	t_command	*subcmd;
	t_command	*next;
	t_command	*before;
}				t_command;

typedef struct s_info
{
	int			i_fds;
	int			i_childs;
	int			i_wait;
	int			fd_file_r;
	int			fd_file_w;
	int			offset;
	int			ac;
	int			str_i;
	char		*env;
	char		*limiter;
	int			i_limiter;
	char		*path_commd;
	char		**envp;
	int			is_for_w;
	int			is_bonus;
	size_t		i_split;
	int			env_null;
	int			is_exit_one;
}				t_info;

char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);

#endif