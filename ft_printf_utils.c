/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:23:07 by yabarhda          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:10 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putchar_ft(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putstr_ft(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr_ft("(null)"));
	while (s[i])
	{
		ft_putchar_ft(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned_ft(unsigned int n)
{
	char	temp;
	int		count;

	count = 0;
	if (n <= 9)
	{
		temp = n + '0';
		count += ft_putchar_ft(temp);
		return (count);
	}
	count += ft_putnbr_unsigned_ft(n / 10);
	temp = (n % 10) + '0';
	count += ft_putchar_ft(temp);
	return (count);
}

int	ft_putnbr_ft(int n)
{
	char	temp;
	int		count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr_ft("-2147483648"));
		n = -n;
		count += ft_putchar_ft('-');
	}
	if (n <= 9)
	{
		temp = n + '0';
		count += ft_putchar_ft(temp);
		return (count);
	}
	count += ft_putnbr_ft(n / 10);
	temp = (n % 10) + '0';
	count += ft_putchar_ft(temp);
	return (count);
}

int	ft_putnbr_hexa_c_ft(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count = ft_putnbr_hexa_c_ft(n / 16);
	count += ft_putchar_ft(base[n % 16]);
	return (count);
}
