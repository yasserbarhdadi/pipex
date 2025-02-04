/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:39:39 by yabarhda          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:06 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_putnbr_pointer_ft(unsigned long n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count = ft_putnbr_pointer_ft(n / 16);
	count += ft_putchar_ft(base[n % 16]);
	return (count);
}

static int	ft_putnbr_hexa_ft(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count = ft_putnbr_hexa_ft(n / 16);
	count += ft_putchar_ft(base[n % 16]);
	return (count);
}

static int	case_handling(char c, long n)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr_ft((int)n);
	else if (c == 'c')
		count += ft_putchar_ft((char)n);
	else if (c == 'u')
		count += ft_putnbr_unsigned_ft((unsigned int)n);
	else if (c == 'X')
		count += ft_putnbr_hexa_ft((unsigned int)n);
	else if (c == 'x')
		count += ft_putnbr_hexa_c_ft((unsigned int)n);
	else if (c == 'p')
	{
		if (n == 0)
			return (ft_putstr_ft("(nil)"));
		count += ft_putstr_ft("0x");
		count += ft_putnbr_pointer_ft((unsigned long)n);
	}		
	return (count);
}

static int	check(va_list args, const char *s)
{
	int		count;
	int		i;
	char	t;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			t = s[i + 1];
			if (t == 'd' || t == 'i' || t == 'c' || t == 'u'
				|| t == 'x' || t == 'X' || t == 'p')
				count += case_handling(t, va_arg(args, long));
			else if (t == 's')
				count += ft_putstr_ft(va_arg(args, char *));
			else if (t == '%')
				count += ft_putchar_ft('%');
			i++;
		}
		else
			count += ft_putchar_ft(s[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;

	if (!s)
		return (-1);
	count = 0;
	va_start(args, s);
	count += check(args, s);
	va_end(args);
	return (count);
}
