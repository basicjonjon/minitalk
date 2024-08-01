/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:58:35 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:44 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_putparam(char c, int *res, va_list args)
{
	if (c == 'c')
		*res += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*res += ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		*res += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		*res += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		*res += ft_putnbrbase(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		*res += ft_putnbrbase(va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		*res += ft_putchar('%');
	else if (c == 'p')
		*res += ft_putadresse(va_arg(args, void *), "0123456789abcdef");
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			res;

	va_start(args, str);
	if (!str)
		return (1);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_putparam(str[++i], &res, args);
		else
		{
			ft_putchar(str[i]);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
