/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:41:30 by yabarhda          #+#    #+#             */
/*   Updated: 2025/01/24 17:42:23 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

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
	int	i;

	i = 0;
	while (i < (args->ac - 1))
	{
		free(args->pipe[i]);
		i++;
	}
	free(args->pipe);
	free(args->pid);
	exit(code);
}
