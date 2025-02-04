/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:44:51 by yabarhda          #+#    #+#             */
/*   Updated: 2025/02/02 20:01:48 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_in(char *argv[], t_list *args)
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

void	check_out(char *a[], t_list *args)
{
	if (access(a[args->ac + 2], F_OK) == -1)
		args->out = open(a[args->ac + 2], O_CREAT | O_WRONLY, 420);
	else if (access(a[args->ac + 2], W_OK) == -1)
		(ft_printf("%s: permission denied: %s\n", a[0], a[args->ac + 2]), \
		free_n_exit(args, 1));
	else
		args->out = open(a[args->ac + 2], O_WRONLY | O_TRUNC);
	if (args->out == -1)
		(ft_printf("%s: no such file or directory: %s\n", \
		a[0], a[args->ac + 2]), free_n_exit(args, 1));
}

static char	*get_path(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
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
	char	**arr;
	char	*path;
	char	*str;
	int		i;

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

	if (argc == 5)
	{
		args.ac = argc - 3;
		main_handle(argv, &args, envp);
	}
	else
		ft_printf("Usage: %s file1 cmd1 cmd2 file2\n", argv[0]);
	return (0);
}
