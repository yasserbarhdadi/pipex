/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:57:51 by yabarhda          #+#    #+#             */
/*   Updated: 2025/02/02 13:59:45 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(s);
	d = (char *)malloc(src_len + 1 * sizeof(char));
	if (!d)
		return (NULL);
	while (i < (src_len + 1))
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin_2(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2);
	dest = (char *)malloc((s1_len + s2_len) * (sizeof(char) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] && i < s1_len - 1)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i++] = '/';
	dest[i] = '\0';
	ft_strlcat(dest, s2, s2_len + s1_len + 1);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcat(dest, s2, s2_len + s1_len + 1);
	return (dest);
}
