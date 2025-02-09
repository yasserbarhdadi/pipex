/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:49:06 by yabarhda          #+#    #+#             */
/*   Updated: 2025/02/08 09:06:37 by yabarhda         ###   ########.fr       */
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

void	exec_cmd(char *a[], t_list *s, int i, char *envp[])
{
	char	**av;

	if (i == 0)
	{
		check_in(a, s);
		(dup2(s->in, 0), close(s->in), dup2(s->pipe[1], 1));
	}
	else if (i == 1)
	{
		check_out(a, s);
		(dup2(s->out, 1), close(s->out), dup2(s->pipe[0], 0));
	}
	(close(s->pipe[0]), close(s->pipe[1]));
	av = ft_split(a[i + 2], ' ');
	if (!av || !av[0])
		(print_error(a[0], 13, av[0]), free(av), free_n_exit(s, 126));
	if (execve(filename(av[0], envp, s), av, envp) == -1)
	{
		if (errno == 2)
			(print_error(a[0], 127, av[0]), free_arr(av), free_n_exit(s, 127));
		else
			(print_error(a[0], errno, av[0]), free_arr(av), \
			free_n_exit(s, 126));
	}
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
	else if (WIFSIGNALED(args->status))
		free_n_exit(args, WTERMSIG(args->status));
}

void	print_error(char *name, int code, char *err)
{
	if (code == 127)
		ft_printf("%s: Command not found: %s\n", name, err);
	else
		ft_printf("%s: %s: %s\n", name, strerror(code), err);
}
