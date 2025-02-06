/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:39:48 by yabarhda          #+#    #+#             */
/*   Updated: 2025/01/25 12:50:27 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "utils.h"

typedef struct s_list {
	int		i;
	int		in;
	int		out;
	int		ac;
	int		pipe[2];
	int		status;
	char	**arr;
	char	*path;
	char	*str;
	pid_t	*pid;
}			t_list;

void	main_handle(char *argv[], t_list *args, char *envp[]);
char	*filename(char *cmd, char *envp[], t_list *args);
void	check_in(char *argv[], t_list *args);
void	check_out(char *a[], t_list *args);
void	free_n_exit(t_list *args, int code);
void	free_arr(char **arr);
void	print_error(char *name, int code, char *err);

#endif