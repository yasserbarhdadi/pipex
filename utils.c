/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:49:06 by yabarhda          #+#    #+#             */
/*   Updated: 2025/01/26 14:40:53 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_n_exit(t_list *args, int code)
{
	free(args->pid);
	exit(code);
}

void	exec_cmd(char *a[], t_list *args, int i, char *envp[])
{
	char	**av;

	if (i == 0)
		(check_in(a, args), dup2(args->in, 0), close(args->in), \
		dup2(args->pipe[1], 1));
	else if (i == 1)
		(check_out(a, args), dup2(args->out, 1), close(args->out), \
		dup2(args->pipe[0], 0));
	close(args->pipe[0]);
	close(args->pipe[1]);
	av = ft_split(a[i + 2], ' ');
	if (!av[0])
		(ft_printf("%s: permission denied: %s\n", a[0], av[0]), free(av), \
		free_n_exit(args, 126));
	if (execve(filename(av[0], envp), av, envp) == -1)
		(ft_printf("%s: command not found: %s\n", a[0], av[0]), \
		free_arr(av), free_n_exit(args, 127));
}

void	main_handle(char *argv[], t_list *args, char *envp[])
{
	int		i;

	i = 0;
	args->pid = (pid_t *)malloc(sizeof(pid_t) * args->ac);
	if (!args->pid)
		exit(1);
	if (pipe(args->pipe) == -1)
		free_n_exit(args, errno);
	while (i < args->ac)
	{
		args->pid[i] = fork();
		if (args->pid[i] == -1)
			free_n_exit(args, errno);
		if (args->pid[i] == 0)
			exec_cmd(argv, args, i, envp);
		i++;
	}
	(close(args->pipe[0]), close(args->pipe[1]));
	i = 0;
	while (i < args->ac && waitpid(args->pid[i], &args->status, 0) > 0)
		i++;
	if (WIFEXITED(args->status))
		free_n_exit(args, WEXITSTATUS(args->status));
	else
		free_n_exit(args, 1);
}
