/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:40:08 by yabarhda          #+#    #+#             */
/*   Updated: 2025/02/02 13:44:41 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdarg.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

int		ft_strchr(const char *s, char c);
int		ft_printf(const char *s, ...);
int		ft_putchar_ft(char c);
int		ft_putstr_ft(char *s);
int		ft_putnbr_unsigned_ft(unsigned int n);
int		ft_putnbr_ft(int n);
int		ft_putnbr_hexa_c_ft(unsigned int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	**ft_split(char const *s, char c);
char	*ft_strjoin_2(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd, int flag);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

#endif