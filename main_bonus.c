/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:54:30 by yabarhda          #+#    #+#             */
/*   Updated: 2025/02/02 15:17:35 by yabarhda         ###   ########.fr       */
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
				ft_printf("%s: no such file or directory: %s\n", argv[0], \
				argv[1]);
			else if (access(argv[1], R_OK) == -1)
				ft_printf("%s: permission denied: %s\n", argv[0], argv[1]);
			free_n_exit(args, 1);
		}
	}
	else
		args->in = args->fds[0];
}

void	check_out(char *a[], t_list *args)
{
	int	f;

	if (access(a[args->ac + 2 + args->o_ap], F_OK) == -1)
		args->out = open(a[args->ac + 2 + args->o_ap], O_CREAT | O_WRONLY, 420);
	else if (access(a[args->ac + 2 + args->o_ap], W_OK) == -1)
		(ft_printf("%s: permission denied: %s\n", a[0], \
		a[args->ac + 2 + args->o_ap]), free_n_exit(args, 1));
	else
	{
		f = 512;
		if (args->o_ap == 1)
			f *= 2;
		args->out = open(a[args->ac + 2 + args->o_ap], O_WRONLY | f);
	}
	if (args->out == -1)
		(ft_printf("%s: no such file or directory: %s\n", \
		a[0], a[args->ac + 2 + args->o_ap]), free_n_exit(args, 1));
}

static char	*get_path(char *envp[])
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
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

char	*filename(char *cmd, char *envp[])
{
	char	*path;
	int		i;
	char	**arr;
	char	*str;

	if (!ft_strchr(cmd, '/'))
		return (cmd);
	path = get_path(envp);
	if (!path)
		return (NULL);
	arr = ft_split(path, ':');
	i = 0;
	while (arr[i])
	{
		if (i == 0)
			str = ft_strjoin_2(&arr[i][5], cmd);
		else
			str = ft_strjoin_2(arr[i], cmd);
		if (!access(str, F_OK | X_OK))
			return (str);
		free(str);
		i++;
	}
	free_arr(arr);
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
