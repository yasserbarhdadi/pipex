/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:54:30 by yabarhda          #+#    #+#             */
/*   Updated: 2025/02/08 08:57:15 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	check_in(char *argv[], t_list *args)
{
	if (args->o_ap == 0)
	{
		args->in = open(argv[1], O_RDONLY);
		if (args->in == -1)
		{
			if (access(argv[1], F_OK) == -1)
				print_error(argv[0], errno, argv[1]);
			else if (access(argv[1], R_OK) == -1)
				print_error(argv[0], errno, argv[1]);
			free_n_exit(args, 1);
		}
	}
	else
		args->in = args->fds[0];
}

void	check_out(char *a[], t_list *s)
{
	int	f;

	if (access(a[s->ac + 2 + s->o_ap], F_OK) == -1)
		s->out = open(a[s->ac + 2 + s->o_ap], O_CREAT | O_WRONLY, 420);
	else if (access(a[s->ac + 2 + s->o_ap], W_OK) == -1)
		(print_error(a[0], errno, a[s->ac + 2 + s->o_ap]), free_n_exit(s, 1));
	else
	{
		f = 512;
		if (s->o_ap == 1)
			f *= 2;
		s->out = open(a[s->ac + 2 + s->o_ap], O_WRONLY | f);
	}
	if (s->out == -1)
		(print_error(a[0], errno, a[s->ac + 2 + s->o_ap]), free_n_exit(s, 1));
}

static char	*get_path(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			path = ft_strnstr(envp[i], "PATH=", 5);
			break ;
		}
		i++;
	}
	return (path);
}

char	*filename(char *cmd, char *envp[], t_list *args)
{
	if (!ft_strchr(cmd, '/'))
		return (cmd);
	args->path = get_path(envp);
	if (!args->path)
		return (cmd);
	args->arr = ft_split(args->path, ':');
	if (!args->arr)
		return (cmd);
	args->i = 0;
	while (args->arr[args->i])
	{
		if (args->i == 0)
			args->str = ft_strjoin_2(&args->arr[args->i][5], cmd);
		else
			args->str = ft_strjoin_2(args->arr[args->i], cmd);
		if (!access(args->str, F_OK))
			return (args->str);
		free(args->str);
		args->i++;
	}
	free_arr(args->arr);
	return (cmd);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	args;

	if (argc >= 5)
	{
		args.o_ap = 0;
		if (!ft_strcmp(argv[1], "here_doc"))
			here_doc_read(argv, &args);
		args.ac = argc - 3 - args.o_ap;
		main_handle(argv, &args, envp);
	}
	else
	{
		ft_printf("Usage: %s file1 cmd1 cmd2 cmd3 ... cmdn file2\n", argv[0]);
		ft_printf("Usage: %s here_doc LIMITER cmd1 cmd2 ... cmdn file\n", \
		argv[0]);
	}
	return (0);
}
