/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:54:44 by yabarhda          #+#    #+#             */
/*   Updated: 2025/01/25 12:57:14 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include "utils.h"

typedef struct s_list {
	int		in;
	int		out;
	int		ac;
	int		**pipe;
	int		o_ap;
	int		fds[2];
	int		status;
	pid_t	*pid;
}			t_list;

void	main_handle(char *argv[], t_list *args, char *envp[]);
char	*filename(char *cmd, char *envp[]);
void	check_in(char *argv[], t_list *args);
void	check_out(char *a[], t_list *args);
void	here_doc_read(char *argv[], t_list *args);
void	free_n_exit(t_list *args, int code);
void	free_arr(char **arr);

#endif